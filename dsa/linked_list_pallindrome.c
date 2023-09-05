#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct linkedlist {
    node *head;
} linkedlist;

void insert(linkedlist *ll, int value);
int is_pallindrome(linkedlist *ll);
void print_list(linkedlist *ll);
void reverse(linkedlist *ll);
int size(linkedlist *ll);
node *_reverse(node *node);
void __free(linkedlist *ll);

int main(int argc, char ** argv) {
    // ODD numbered pallindrome
    linkedlist numbers;
    numbers.head = NULL;

    insert(&numbers, 1);
    insert(&numbers, 2);
    insert(&numbers, 3);
    insert(&numbers, 4);
    insert(&numbers, 3);
    insert(&numbers, 2);
    insert(&numbers, 1);

    printf("\nSize: %d", size(&numbers));
    printf("\nIs pallindrome: %d", is_pallindrome(&numbers));
    print_list(&numbers);
    __free(&numbers);

    printf("\n\n>>>>>>>>>");
    // ODD numbered NOT a pallindrome
    linkedlist numbers2;
    numbers2.head = NULL;

    insert(&numbers2, 1);
    insert(&numbers2, 2);
    insert(&numbers2, 3);
    insert(&numbers2, 4);
    insert(&numbers2, 3);
    insert(&numbers2, 2);
    insert(&numbers2, 2);

    printf("\nSize: %d", size(&numbers2));
    printf("\nIs pallindrome: %d", is_pallindrome(&numbers2));
    print_list(&numbers2);
    __free(&numbers2);

    printf("\n\n>>>>>>>>>");
    // EVEN numbered a pallindrome
    linkedlist numbers3;
    numbers3.head = NULL;

    insert(&numbers3, 1);
    insert(&numbers3, 2);
    insert(&numbers3, 3);
    insert(&numbers3, 4);
    insert(&numbers3, 4);
    insert(&numbers3, 3);
    insert(&numbers3, 2);
    insert(&numbers3, 1);

    printf("\nSize: %d", size(&numbers3));
    printf("\nIs pallindrome: %d", is_pallindrome(&numbers3));
    print_list(&numbers3);
    __free(&numbers3);

    printf("\n\n>>>>>>>>>");
    // EVEN numbered NOT a pallindrome
    linkedlist numbers4;
    numbers4.head = NULL;

    insert(&numbers4, 1);
    insert(&numbers4, 2);
    insert(&numbers4, 3);
    insert(&numbers4, 4);
    insert(&numbers4, 4);
    insert(&numbers4, 3);
    insert(&numbers4, 2);
    insert(&numbers4, 2);

    printf("\nSize: %d", size(&numbers4));
    printf("\nIs pallindrome: %d", is_pallindrome(&numbers4));
    print_list(&numbers4);
    __free(&numbers4);

    printf("\n");
    return EXIT_SUCCESS;
}

void insert(linkedlist *ll, int value) {
    if (ll == NULL) {
        return;
    }

    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("\n!!Cannot allocate new node!!");
        return;
    }
    new_node -> value = value;
    new_node -> next = NULL;

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

int is_pallindrome(linkedlist *ll) {
    int ret_val = 1;
    if (ll == NULL) {
        return ret_val;
    }
    
    // find the middle index, consider even odd lengths
    int n = size(ll);
    int mid_index = (n / 2) + (n % 2 == 0 ? 0 : 1);
    node *middle;

    // traverse to the middle node
    node *tmp = ll -> head;
    for (int i = 0; i < mid_index - 1; i++) {
        tmp = tmp -> next;
    }

    // reverse nodes after the middle node
    middle = tmp;
    middle -> next = _reverse(middle -> next);

    // traverse the length of shorter list (right to end)
    node *left = ll -> head;
    node *right = middle -> next;
    while (right != NULL) {
        if (left -> value != right -> value) {
            ret_val = 0;
            break;
        }
        left = left -> next;
        right = right -> next;
    }

    // restore the list
    middle -> next = _reverse(middle -> next);
    return ret_val;
}

void print_list(linkedlist *ll) {
    if (ll == NULL) {
        return;
    }

    printf("\n");
    node *tmp = ll -> head;
    while (tmp != NULL) {
        printf("%d -> ", tmp -> value);
        tmp = tmp -> next;
    }
    printf("NULL");
}

void reverse(linkedlist *ll) {
    if (ll == NULL) {
        return;
    }
    ll -> head = _reverse(ll -> head);
}

node *_reverse(node *head) {
    node *prev = NULL;
    if (head == NULL) {
        return prev;
    }

    node *tmp = head;
    while (tmp != NULL) {
        node *swap = tmp -> next;
        tmp -> next = prev;
        prev = tmp;
        tmp = swap;
    }
    return prev;
}

int size(linkedlist *ll) {
    int len = 0;
    if (ll == NULL) {
        return len;
    }

    node *tmp = ll -> head;
    while (tmp != NULL) {
        len++;
        tmp = tmp -> next;
    }
    return len;
}

void __free(linkedlist *ll) {
    if (ll == NULL) {
        return;
    }

    node *tmp = ll -> head;
    ll -> head = NULL;
    while (tmp != NULL) {
        node *to_delete = tmp;
        tmp = tmp -> next;

        to_delete -> next = NULL;
        free(to_delete);
    }
}

