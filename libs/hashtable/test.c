#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "hashtable.h"

void free_object(void *object);
void generate_random_alphanum_str(uint32_t size, char *str);
char *get_from_hash_table_s(hash_table *ht, const char *key, uint32_t key_len);

int main(int argc, char **argv) {
    hash_table *ht = hash_table_create(1024, NULL, NULL, free_object);
    get_from_hash_table_s(ht, "testk1", 6);

    hash_table_put(ht, "testk1", 6, "value");
    hash_table_put(ht, "testk2", 6, "value1");
    get_from_hash_table_s(ht, "testk1", 6);
    get_from_hash_table_s(ht, "testk2", 6);

    hash_table_put(ht, "testk2", 6, "value3");
    get_from_hash_table_s(ht, "testk2", 6);

    hash_table_remove(ht, "testk1", 6);
    hash_table_remove(ht, "testk2", 6);

    hash_table_destroy(ht);
    ht = NULL;
    return EXIT_SUCCESS;
}

char *get_from_hash_table_s(hash_table *ht, const char *key, uint32_t key_len) {
    char *value = (char *) hash_table_get(ht, key, key_len);
    printf("Get for key - %s: %s\n", key, value);
    return value;
}

void generate_random_alphanum_str(uint32_t size, char *str) {
    
}

void free_object(void *object) {
    // TODO
    printf("Free object: %s\n", (char *) object);
    /*free(object);*/
    /*object = NULL;*/
}

