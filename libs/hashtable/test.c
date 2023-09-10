#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hashtable.h"

const char *CHARSET_APLHANUM = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
const int CHARSET_ALPHANUM_SIZE = 62;

void free_object(void *object);
char *get_from_hash_table_s(hash_table *ht, const char *key, uint32_t key_len);
void generate_random_str(const char *charset, const uint32_t charset_size, uint32_t size, char *str);
void generate_random_alphanum_str(uint32_t size, char *str);

void test_auto(uint32_t argc, char **argv);
void test_auto_gets(uint64_t ht_size, uint32_t kv_size, uint32_t kv_count);
void test_auto_replace(uint64_t ht_size, uint32_t kv_size, uint32_t kv_count);
void test_auto_remove(uint64_t ht_size, uint32_t kv_size, uint32_t kv_count);
void test_perf_auto_gets(uint64_t ht_size, uint32_t kv_size, uint32_t kv_count);
void test_perf_auto_replace(uint64_t ht_size, uint32_t kv_size, uint32_t kv_count);
void test_perf_auto_remove(uint64_t ht_size, uint32_t kv_size, uint32_t kv_count);

int main(int argc, char **argv) {
    if (argc > 4) {
        test_auto(argc, argv);
        return EXIT_SUCCESS;
    }

    // test manual
    hash_table *ht = hash_table_create(1024, NULL, NULL, free_object);

    char *k1 = strdup("testk1");
    char *k2 = strdup("testk2");
    char *k3 = strdup("testk3");

    hash_table_put(ht, k1, strlen(k1), strdup("value1"));
    hash_table_put(ht, k2, strlen(k2), strdup("value2"));
    get_from_hash_table_s(ht, k1, strlen(k1));
    get_from_hash_table_s(ht, k2, strlen(k2));

    hash_table_put(ht, k2, strlen(k2), strdup("value2_updated"));
    get_from_hash_table_s(ht, k2, strlen(k2));

    hash_table_put(ht, k3, strlen(k3), strdup("value3"));
    hash_table_remove(ht, k1, strlen(k1));
    hash_table_remove(ht, k2, strlen(k2));

    get_from_hash_table_s(ht, k1, strlen(k1));
    get_from_hash_table_s(ht, k2, strlen(k2));
    get_from_hash_table_s(ht, k3, strlen(k3));

    free(k1);
    free(k2);
    free(k3);

    hash_table_destroy(ht);
    ht = NULL;
    return EXIT_SUCCESS;
}

void free_object(void *object) {
    /*printf("Free object: %s\n", (char *) object);*/
    free(object);
    object = NULL;
}

char *get_from_hash_table_s(hash_table *ht, const char *key, uint32_t key_len) {
    char *value = (char *) hash_table_get(ht, key, key_len);
    /*printf("Get for key - %s: %s\n", key, value);*/
    return value;
}

void generate_random_str(const char *charset, const uint32_t charset_size, uint32_t size, char *str) {
    if (size && str) {
        for (uint8_t i = 0; i < size - 2; i++) {
            uint8_t index = rand() % charset_size;
            str[i] = charset[index];
        }
        str[size - 1] = 0;
    }
}

void generate_random_alphanum_str(uint32_t size, char *str) {
    generate_random_str(CHARSET_APLHANUM, CHARSET_ALPHANUM_SIZE, size, str);
}

void test_auto(uint32_t argc, char **argv) {
    srand(time(NULL));
    uint64_t ht_size = atoi(argv[1]);
    uint32_t kv_size = atoi(argv[2]);
    uint32_t kv_count = atoi(argv[3]);
    uint32_t mode = atoi(argv[4]);

    if (mode == 0) {
        test_auto_gets(ht_size, kv_size, kv_count);
        test_auto_replace(ht_size, kv_size, kv_count);
        test_auto_remove(ht_size, kv_size, kv_count);
    } else{
        test_perf_auto_gets(ht_size, kv_size, kv_count);
    }
}

void test_auto_gets(uint64_t ht_size, uint32_t kv_size, uint32_t kv_count) {
    hash_table *ht = hash_table_create(ht_size, NULL, NULL, free_object);
    printf("Hashtable size: %lld\n", ht_size);

    time_t t_start_gets;
    time(&t_start_gets);

    for (uint32_t i = 0; i < kv_count; i++) {
        char *key = malloc((kv_size + 1) * sizeof(char));
        generate_random_alphanum_str(kv_size + 1, key);
        char *value = strdup(key);
        /*printf("%s, %s\n", key, value);*/

        hash_table_put(ht, key, kv_size, value);
        char *actual_value = get_from_hash_table_s(ht, key, kv_size);

        if (strncmp(value, actual_value, kv_size) != 0) {
            printf("Mismatched k, v pair\n");
            exit(EXIT_FAILURE);
        }
        free(key);
        key = NULL;
    }

    time_t t_ends_gets;
    time(&t_ends_gets);
    printf("Put and Get Operations: %d completed in %lds (strncmp assertion time included)\n", kv_count, (t_ends_gets - t_start_gets));

    time_t t_start_destroy;
    time(&t_start_destroy);
    hash_table_destroy(ht);
    time_t t_ends_destroy;
    time(&t_ends_destroy);
    printf("Destroy hash_table in %lds\n", (t_ends_destroy - t_start_destroy));
}

void test_perf_auto_gets(uint64_t ht_size, uint32_t kv_size, uint32_t kv_count) {
    hash_table *ht = hash_table_create(ht_size, NULL, NULL, free_object);
    printf("Hashtable size: %lld\n", ht_size);

    time_t t_start_puts;
    time(&t_start_puts);

    for (uint32_t i = 0; i < kv_count; i++) {
        char *key = malloc((kv_size + 1) * sizeof(char));
        generate_random_alphanum_str(kv_size + 1, key);
        char *value = strdup(key);
        /*printf("%s, %s\n", key, value);*/
        hash_table_put(ht, key, kv_size, value);
        free(key);
        key = NULL;
    }
    time_t t_ends_puts;
    time(&t_ends_puts);
    printf("Put Operations: %d completed in %lds\n", kv_count, (t_ends_puts - t_start_puts));
    printf("Hashcode Perf - ");
    hashcode_stats hc_stats;
    hash_table_hashcode_stats(ht, &hc_stats);
    printf("[size: %lld, used: %lld empty: %lld]\n", hc_stats.size,
            hc_stats.used, hc_stats.size - hc_stats.used);

    time_t t_start_gets;
    time(&t_start_gets);

    for (uint32_t i = 0; i < kv_count; i++) {
        char *key = malloc((kv_size + 1) * sizeof(char));
        generate_random_alphanum_str(kv_size + 1, key);
        hash_table_get(ht, key, kv_size);
        free(key);
        key = NULL;
    }
    time_t t_ends_gets;
    time(&t_ends_gets);
    printf("Get Operations: %d completed in %lds\n", kv_count, (t_ends_gets - t_start_gets));

    time_t t_start_destroy;
    time(&t_start_destroy);
    hash_table_destroy(ht);
    time_t t_ends_destroy;
    time(&t_ends_destroy);
    printf("Destroy hash_table in %lds\n", (t_ends_destroy - t_start_destroy));
}

void test_auto_replace(uint64_t ht_size, uint32_t kv_size, uint32_t kv_count) {
    // TODO
}

void test_auto_remove(uint64_t ht_size, uint32_t kv_size, uint32_t kv_count) {
    // TODO
}

void test_perf_auto_replace(uint64_t ht_size, uint32_t kv_size, uint32_t kv_count) {
    // TODO
}

void test_perf_auto_remove(uint64_t ht_size, uint32_t kv_size, uint32_t kv_count) {
    // TODO
}

