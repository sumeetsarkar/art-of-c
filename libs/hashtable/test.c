#include <stdint.h>
#include <stdlib.h>
#include "hashtable.h"

uint32_t hash_key(const char *key, uint32_t key_len);
void free_object(void *object);

int main(int argc, char **argv) {
    hash_table *ht = hash_table_create(1024, hash_key, NULL, free_object);
    hash_table_destroy(ht);
    ht = NULL;
    return EXIT_SUCCESS;
}

uint32_t hash_key(const char *key, uint32_t key_len) {
    return 0;
}

void free_object(void *object) {
  
}

