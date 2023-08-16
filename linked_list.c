#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE_VALUE 32

typedef struct node {
    char value[MAX_SIZE_VALUE];
    struct node *next;
} node;

void ll_print(node *start);
void ll_insert(node *start, const char *value);
node *ll_find(node *start, const char *value);
int ll_delete(node *start, const char *value); // deletes first found value
node *create_new_node(const char *value);

int main(int argc, char **argv) {

    node *list1 = create_new_node("\\[__$head$__]\\");
    ll_print(list1);

    printf("\n\n++ Adding more values");
    ll_insert(list1, "Red");
    ll_insert(list1, "Green");
    ll_insert(list1, "Blue");

    ll_print(list1);
    printf("\nSearching for Red\t%d", ll_find(list1, "Red") != NULL);
    printf("\nSearching for Green\t%d", ll_find(list1, "Green") != NULL);
    printf("\nSearching for Blue\t%d", ll_find(list1, "Blue") != NULL);
    printf("\nSearching for Yellow\t%d", ll_find(list1, "Yellow") != NULL);
    
    ll_insert(list1, "Cyan");
    ll_insert(list1, "Magenta");
    ll_insert(list1, "Yellow");

    printf("\n\n++ Adding more values");
    ll_print(list1);

    printf("\nSearching for Cyan\t%d", ll_find(list1, "Cyan") != NULL);
    printf("\nSearching for Magenta\t%d", ll_find(list1, "Magenta") != NULL);
    printf("\nSearching for Yellow\t%d", ll_find(list1, "Yellow") != NULL);

    printf("\n-- Deleting value Red\t%d", ll_delete(list1, "Red"));
    printf("\nSearching for Red\t%d", ll_find(list1, "Red") != NULL);
    ll_print(list1);

    printf("\n-- Deleting value Cyan\t%d", ll_delete(list1, "Cyan"));
    printf("\n-- Deleting value Blue\t%d", ll_delete(list1, "Blue"));
    printf("\n-- Deleting value Green\t%d", ll_delete(list1, "Green"));
    printf("\n-- Deleting value Red\t%d", ll_delete(list1, "Red"));
    ll_print(list1);
    printf("\n-- Deleting value Magenta\t%d", ll_delete(list1, "Magenta"));
    printf("\n-- Deleting value Yellow\t%d", ll_delete(list1, "Yellow"));
    ll_print(list1);

    printf("\n\n++ Adding more values");
    ll_insert(list1, "Cyan");
    ll_insert(list1, "Magenta");
    ll_insert(list1, "Yellow");
    ll_print(list1);

    printf("\n");
    return 0;
}

node *create_new_node(const char *value) {
   node *new_node = malloc(sizeof(node));
   if (new_node != NULL) {
       strcpy(new_node -> value, value);
       new_node -> next = NULL;
   }
   return new_node;
}

void ll_print(node *start) {
    printf("\nData List ----- Start");
    node *tmp = start -> next;

    while (tmp != NULL) {
        printf("\n\tvalue: %s", tmp -> value);
        tmp = tmp -> next;
    }
    printf("\nData List ----- End\n");
}

void ll_insert(node *start, const char *value) {
    node *tmp = start;

    while (tmp -> next != NULL) {
        tmp = tmp -> next;
    }

    node *new_node = create_new_node(value);
    if (new_node == NULL) {
        printf("\n!!Unable to allocate memory!!");
    } else {
        tmp -> next = new_node;
    }
}

node *ll_find(node *start, const char *value) {
    node *tmp = start;
    node *result = NULL;

    while (tmp != NULL) {
        if (strncmp(tmp -> value, value, MAX_SIZE_VALUE) == 0) {
            result = tmp;
            break;
        }
        tmp = tmp -> next;
    }

    return result;
}

int ll_delete(node *start, const char *value) {
    node *tmp = start;
    node *prev = start;
    int ret_val = 0;

    while (tmp != NULL) {
        if (strncmp(tmp -> value, value, MAX_SIZE_VALUE) == 0) {
            // this is the node to be deleted
            ret_val = 1;
            node *to_delete = tmp;
            prev -> next = to_delete -> next;
            free(to_delete);
            break;
        }

        prev = tmp;
        tmp = tmp -> next;
    }
    return ret_val;
}

