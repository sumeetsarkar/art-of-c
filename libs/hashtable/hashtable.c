#include "hashtable.h"

typedef struct _entry {
    char *key;
    size_t key_len;
    void *object;
    entry *next;
} entry;

typedef struct _hash_table {
    uint64_t size;
    hash_function *hash_fn;
    free_function *free_fn;
    entry **entries;
} hash_table;

hash_table *create_new(uint32_t size, hash_function *hash_fn, free_function *free_fn) {
    hash_table *ht = malloc(sizeof(hash_table));
    if (ht != NULL) {
        ht -> size = size;
        ht -> hash_fn = hash_fn;
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

void destroy(hash_table *ht) {
  
}

