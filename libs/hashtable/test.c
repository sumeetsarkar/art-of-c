#include "hashtable.h"
#include <stdint.h>
#include <stdlib.h>

uint32_t hash_key(const char *key, size_t key_len);
void free_object(void *object);

int main(int argc, char **argv) {
  hash_table *ht = create_new(1024, hash_key, free_object);
  destroy(ht);
  ht = NULL;
  return EXIT_SUCCESS;
}

uint32_t hash_key(const char *key, size_t key_len) {
  return 0;
}

void free_object(void *object) {
  
}

