#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint32_t (hash_function) (const char *key, size_t key_len);
typedef void (free_function) (void *object);

typedef struct _entry entry;
typedef struct _hash_table hash_table;

hash_table *create_new(uint32_t size, hash_function *hash_fn, free_function *free_fn);
void destroy(hash_table *ht);
bool put(hash_table *ht, const char *key, size_t key_len, void *value);
void *get(hash_table *ht, const char *key, size_t key_len);
bool remove(hash_table *ht, const char *key, size_t key_len);

#endif

