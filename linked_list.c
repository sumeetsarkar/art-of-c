#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE_VALUE 32

typedef struct node {
    char value[MAX_SIZE_VALUE];
    struct node *next;
} node;

typedef struct linked_list {
    node *head;
} linked_list;

void ll_print(linked_list *ll);
void ll_insert(linked_list *ll, const char *value);
node *ll_find(linked_list *ll, const char *value);
int ll_delete(linked_list *ll, const char *value); // deletes first found value
void reverse(linked_list *ll);
node *create_new_node(const char *value);
void __init(linked_list *ll);
void __reset(linked_list *ll);

int main(int argc, char **argv) {

    linked_list list1;

    __init(&list1);
    ll_print(&list1);

    printf("\n\n++ Adding more values");
    ll_insert(&list1, "Red");
    ll_insert(&list1, "Green");
    ll_insert(&list1, "Blue");
    ll_print(&list1);

    printf("\nSearching for Red\t%d", ll_find(&list1, "Red") != NULL);
    printf("\nSearching for Green\t%d", ll_find(&list1, "Green") != NULL);
    printf("\nSearching for Blue\t%d", ll_find(&list1, "Blue") != NULL);
    printf("\nSearching for Yellow\t%d", ll_find(&list1, "Yellow") != NULL);
    
    ll_insert(&list1, "Cyan");
    ll_insert(&list1, "Magenta");
    ll_insert(&list1, "Yellow");

    printf("\n\n++ Adding more values");
    ll_print(&list1);

    printf("\nSearching for Cyan\t%d", ll_find(&list1, "Cyan") != NULL);
    printf("\nSearching for Magenta\t%d", ll_find(&list1, "Magenta") != NULL);
    printf("\nSearching for Yellow\t%d", ll_find(&list1, "Yellow") != NULL);

    printf("\n-- Deleting value Red\t%d", ll_delete(&list1, "Red"));
    printf("\nSearching for Red\t%d", ll_find(&list1, "Red") != NULL);
    ll_print(&list1);

    printf("\n-- Deleting value Cyan\t%d", ll_delete(&list1, "Cyan"));
    printf("\n-- Deleting value Blue\t%d", ll_delete(&list1, "Blue"));
    printf("\n-- Deleting value Green\t%d", ll_delete(&list1, "Green"));
    printf("\n-- Deleting value Red\t%d", ll_delete(&list1, "Red"));
    ll_print(&list1);
    printf("\n-- Deleting value Magenta\t%d", ll_delete(&list1, "Magenta"));
    printf("\n-- Deleting value Yellow\t%d", ll_delete(&list1, "Yellow"));
    ll_print(&list1);

    printf("\n\n++ Adding more values");
    ll_insert(&list1, "Cyan");
    ll_insert(&list1, "Magenta");
    ll_insert(&list1, "Yellow");
    ll_print(&list1);

    reverse(&list1);
    ll_print(&list1);
    printf("\n");
    return 0;
}

node *create_new_node(const char *value) {
   node *new_node = malloc(sizeof(node));
   if (new_node != NULL) {
       strncpy(new_node -> value, value, MAX_SIZE_VALUE);
       new_node -> next = NULL;
   }
   return new_node;
}

void ll_print(linked_list *ll) {
    printf("\nData List ----- head");
    node *tmp = ll -> head;

    while (tmp != NULL) {
        printf("\n\tvalue: %s", tmp -> value);
        tmp = tmp -> next;
    }
    printf("\nData List ----- End\n");
}

void ll_insert(linked_list *ll, const char *value) {
    if (value != NULL) {

        node *new_node = create_new_node(value);
        if (new_node == NULL) {
            printf("\n!!Unable to allocate memory!!");

        } else {
            if (ll -> head == NULL) {
                ll -> head = new_node;

            } else {
                node *tmp = ll -> head;
                while (tmp -> next != NULL) {
                    tmp = tmp -> next;
                }
                tmp -> next = new_node;
            }
        }
    }
}

node *ll_find(linked_list *ll, const char *value) {
    node *tmp = ll -> head;
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

int ll_delete(linked_list *ll, const char *value) {
    node *tmp = ll -> head;
    node *prev = ll -> head;
    int ret_val = 0;

    while (tmp != NULL) {
        if (strncmp(tmp -> value, value, MAX_SIZE_VALUE) == 0) {
            // this is the node to be deleted
            ret_val = 1;
            node *to_delete = tmp;

            if (to_delete == ll -> head) {
                ll -> head = ll -> head -> next != NULL ? ll -> head -> next : NULL;
            } else {
                prev -> next = to_delete -> next;
            }
            free(to_delete);
            break;
        }

        prev = tmp;
        tmp = tmp -> next;
    }
    return ret_val;
}

void reverse(linked_list *ll) {
    node *start = ll -> head;
    node *prev = NULL;

    while (start != NULL) {
        node *tmp = start -> next;
        start -> next = prev;
        prev = start;
        start = tmp;
    }
    ll -> head = prev;
}

void __init(linked_list *ll) {
    __reset(ll);
}

void __reset(linked_list *ll) {
    ll -> head = NULL;
}

