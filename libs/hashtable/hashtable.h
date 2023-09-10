#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint32_t (hash_function) (const char *key, uint32_t key_len);
typedef bool (equals_function) (const char *this_key, uint32_t this_key_len,
                                const char *that_key, uint32_t that_key_len);
typedef void (free_function) (void *object);

typedef struct _entry entry;
typedef struct _hash_table hash_table;

hash_table *hash_table_create(uint32_t size, hash_function *hash_fn,
                              equals_function *equals_fn,
                              free_function *free_fn);
void hash_table_destroy(hash_table *ht);
bool hash_table_put(hash_table *ht, const char *key, uint32_t key_len, void *value);
void *hash_table_get(hash_table *ht, const char *key, uint32_t key_len);
bool hash_table_remove(hash_table *ht, const char *key, uint32_t key_len);

#endif

