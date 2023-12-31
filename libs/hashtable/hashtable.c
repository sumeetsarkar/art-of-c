#include "hashtable.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

uint64_t hash_table_get_index(hash_table *ht, const char *key, uint32_t key_len) {
    uint64_t hash_key = ht -> hash_fn(key, key_len);
    return hash_key % ht -> size;
}

uint64_t hash_table_hash(const char *key, uint32_t key_len) {
    uint64_t hashcode = 0;
    for (int i = 0; i < key_len; i++) {
        hashcode += key[i] + 7;
        hashcode *= (key[i] + 7);
    }
    /*printf("Hashcode for key: %s with key_len: %d, %lld\n", key, key_len, hashcode);*/
    return hashcode;
}

bool hash_table_equals(const char *this_key, uint32_t this_key_len,
            const char *that_key, uint32_t that_key_len) {
    if (this_key_len != that_key_len)
        return false;
    return strncmp(this_key, that_key, this_key_len) == 0;
}

entry *_hash_table_get(hash_table *ht, const char *key, uint32_t key_len) {
    uint32_t index = hash_table_get_index(ht, key, key_len);
    entry *_entry = ht -> entries[index];

    if (_entry == NULL)
        return NULL;

    entry *tmp = _entry;
    while (tmp) {
        if (ht -> equals_fn(key, key_len, tmp -> key, tmp -> key_len)) {
            return tmp;
        }
        tmp = tmp -> next;
    }
    return NULL;
}

bool hash_table_put(hash_table *ht, const char *key, uint32_t key_len, void *value) {
    entry *found = _hash_table_get(ht, key, key_len);
    if (found) {
        ht -> free_fn(found -> object);
        found -> object = value;
        return true;
    }

    uint32_t index = hash_table_get_index(ht, key, key_len);
    entry *_entry = ht -> entries[index];
    entry *_new_entry = malloc(sizeof(entry));
    if (_new_entry == NULL)
        return false;

    _new_entry -> key = malloc((key_len + 1) * sizeof(char));
    strncpy(_new_entry -> key, key, key_len);
    _new_entry -> key_len = key_len;
    _new_entry -> object = value;
    _new_entry -> next = _entry;

    ht -> entries[index] = _new_entry;
    return true;
}

void *hash_table_get(hash_table *ht, const char *key, uint32_t key_len) {
    entry *found = _hash_table_get(ht, key, key_len);
    return found ? found -> object : NULL;
}

bool hash_table_remove(hash_table *ht, const char *key, uint32_t key_len) {
    uint32_t index = hash_table_get_index(ht, key, key_len);
    entry *_entry = ht -> entries[index];

    if (_entry == NULL)
        return NULL;

    entry *tmp = _entry;
    entry *prev = NULL;
    while (tmp) {
        if (ht -> equals_fn(key, key_len, tmp -> key, tmp -> key_len)) {
            break;
        }
        prev = tmp;
        tmp = tmp -> next;
    }

    if (tmp == NULL)
        return false;

    if (prev) {
        prev -> next = tmp -> next;
    } else {
        ht -> entries[index] = tmp -> next;
    }
    ht -> free_fn(tmp -> object);
    free(tmp);
    return true;
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
    for (int i = 0; i < ht -> size; i++) {
        entry *_entry = ht -> entries[i];
        while (_entry) {
            ht -> free_fn(_entry -> object);
            free(_entry -> key);
            _entry -> key_len = 0;
            entry *_next_entry = _entry -> next;
            _entry -> next = NULL;
            free(_entry);
            _entry = _next_entry;
        }
        ht -> entries[i] = NULL;
    }
    free(ht -> entries);
    free(ht);
    ht = NULL;
}

void hash_table_hashcode_stats(hash_table *ht, hashcode_stats *hc_stats) {
    uint64_t used = 0;
    for (int i = 0; i < ht -> size; i++) {
        if (ht -> entries[i]) {
            used += 1;
        }
    }
    hc_stats -> size = ht -> size;
    hc_stats -> used = used;
}

