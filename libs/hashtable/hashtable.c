#include "hashtable.h"
#include <stdint.h>

typedef struct _entry {
    char *key;
    uint32_t key_len;
    void *object;
    entry *next;
} entry;

typedef struct _hash_table {
    uint64_t size;
    hash_function *hash_fn;
    equals_function *equals_fn;
    free_function *free_fn;
    entry **entries;
} hash_table;

uint32_t hash_table_get_index(hash_table *ht, const char *key, uint32_t key_len) {
    uint32_t hash_key = ht -> hash_fn(key, key_len);
    return hash_key % ht -> size;
}

uint32_t hash_table_hash(const char *key, uint32_t key_len) {
    // TODO
    return 0;
}

bool hash_table_equals(const char *this_key, uint32_t this_key_len,
            const char *that_key, uint32_t that_key_len) {
    // TODO
    return true;
}

bool hash_table_put(hash_table *ht, const char *key, uint32_t key_len, void *value) {
    // TODO
    return false;
}

void *hash_table_get(hash_table *ht, const char *key, uint32_t key_len) {
    uint32_t index = hash_table_get_index(ht, key, key_len);
    entry *_entry = ht -> entries[index];
    if (_entry == NULL)
        return NULL;

    entry *tmp = _entry;
    while (tmp) {
        if (ht -> equals_fn(key, key_len, tmp -> key, tmp -> key_len)) {
        }
    }
    return NULL;
}

bool hash_table_remove(hash_table *ht, const char *key, uint32_t key_len) {
    // TODO
    return false;
}

hash_table *hash_table_create(uint32_t size, hash_function *hash_fn,
                       equals_function *equals_fn, free_function *free_fn) {
    hash_table *ht = malloc(sizeof(hash_table));
    if (ht) {
        ht -> size = size;
        ht -> hash_fn = hash_fn ? hash_fn : hash_table_hash;
        ht -> equals_fn = equals_fn ? equals_fn : hash_table_equals;
        ht -> free_fn = free_fn;
        ht -> entries = calloc(ht -> size, sizeof(entry));

        if (ht -> entries == NULL) {
          ht -> size = 0;
          ht -> hash_fn = NULL;
          ht -> free_fn = NULL;
          free(ht);
          ht = NULL;
        }
    }
    return ht;
}

void hash_table_destroy(hash_table *ht) {
    // TODO
}

