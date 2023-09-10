#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_TABLE 10
#define MAX_SIZE_VALUE 32

typedef struct node {
    char value[MAX_SIZE_VALUE];
    struct node *next;
} node;

node *hash_table[MAX_SIZE_TABLE];

void __init();
void ht_print();
void ht_add(const char *value);
void ht_del(const char *value);
node *ht_get(const char *value);
unsigned int hash(const char *value);
node *create_node(const char *value);

int main(int argc, char **argv) {
    __init();

    ht_add("Lizzy");
    ht_add("Daniel");
    ht_add("Sam");
    printf("\n%s", ht_get("Lizzy") -> value);

    ht_add("Daisy");
    ht_add("Sam");
    ht_add("Cookie");
    ht_add("Honey");
    ht_add("Jack");
    ht_add("Jack");
    ht_add("Zuzu");
    ht_add("Zuzu");

    ht_print();

    printf("\nDeleting Sam");
    ht_del("Sam");
    ht_print();

    printf("\nDeleting Sam again, this should be a NO OP");
    ht_del("Sam");
    ht_print();

    printf("\nDeleting Zuzu");
    ht_del("Zuzu");
    ht_print();

    ht_del("Honey");
    ht_print();
    ht_del("Daisy");
    ht_print();
    ht_del("Cookie");
    ht_print();

    ht_add("Cookie");
    ht_add("Daisy");
    ht_add("Honey");
    ht_add("Sam");
    ht_add("Zuzu");
    ht_print();
    return 0;
}

node *create_node(const char* value) {
    node *new_node = malloc(sizeof(node));
    strncpy(new_node -> value, value, MAX_SIZE_VALUE);
    new_node -> next = NULL;
    return new_node;
}

void ht_add(const char *value) {
    if (value != NULL && ht_get(value) == NULL) {
        node *new_node = create_node(value);
        if (new_node == NULL) {
            printf("\n!!Unable to create new node!!");
        } else {
            const int index = hash(value);
            if (hash_table[index] != NULL) {
                new_node -> next =  hash_table[index];
            }
            hash_table[index] = new_node;
        }
    }
}

void ht_del(const char *value) {
    if (value != NULL) {
        const int index = hash(value);

        if (hash_table[index] != NULL) {
            node *tmp = hash_table[index];
            node *prev = NULL;

            while (tmp != NULL) {
                if (strncmp(tmp -> value, value, MAX_SIZE_VALUE) == 0) {
                    if (prev == NULL) {
                        // the first node in the list is being deleted
                        hash_table[index] = tmp -> next;
                        
                    } else {
                        prev -> next = tmp -> next;
                    }
                    free(tmp);
                    tmp = NULL;
                    break;
                }
                prev = tmp;
                tmp = tmp -> next;
            }
        }
    }
}

node *ht_get(const char *value) {
    node *ret_val = NULL;

    if (value != NULL) {
        const int index = hash(value);

        if (hash_table[index] != NULL) {
            node *tmp = hash_table[index];

            while (tmp != NULL) {
                if (strcmp(tmp -> value, value) == 0) {
                    ret_val = tmp;
                    break;
                }
                tmp = tmp -> next;
            }
        }
    }
    return ret_val;
}

unsigned int hash(const char *value) {
    unsigned int hash_value = 0; 

    if (value != NULL) {

        while (*value != '\0') {
            hash_value += *value + 7;
            hash_value *= hash_value * *value;
            hash_value %= MAX_SIZE_TABLE;
            value ++;
        }
    }
    return hash_value;
}

void __init() {
   for (int i = 0; i < MAX_SIZE_TABLE; i++) {
       hash_table[i] = NULL;
   }
}

void ht_print() {
    printf("\nPrinting hash table");

    for (int i = 0; i < MAX_SIZE_TABLE; i++) {
        printf("\n\tIndex %d", i);
        node *tmp = hash_table[i];

        while (tmp != NULL) {
            printf("\n\t\t%s", tmp -> value);
            tmp = tmp -> next;
        }
    }
    printf("\nEnd");
}

