#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_VALUE 32

typedef struct node {
    char value[MAX_SIZE_VALUE];
    struct node *next;
} node;

typedef struct queue {
    node *head, *tail;
} queue;

void push(queue *q, const char *value);
void poll(queue *q);
node *peek(queue *q);
size_t size(queue *q);
void listq(queue *q);
node *__create_new_node(const char *value);
void __init(queue *q);
void __reset(queue *q);

int main(int argc, char **argv) {
    queue colors;
    __init(&colors);

    push(&colors, "red");
    push(&colors, "green");
    push(&colors, "blue");
    listq(&colors);
    printf("\nSize: %ld", size(&colors));

    poll(&colors);
    listq(&colors);

    poll(&colors);
    listq(&colors);

    printf("\nPeeked: %s", peek(&colors) -> value);
    printf("\nSize: %ld", size(&colors));

    push(&colors, "cyan");
    push(&colors, "magenta");
    push(&colors, "yellow");
    listq(&colors);
    printf("\nSize: %ld", size(&colors));

    printf("\n");
    return 0;
}

void push(queue *q, const char *value) {
    if (value != NULL) {

        node *new_node = __create_new_node(value);
        if (new_node == NULL) {
            printf("\n!!Unable to create new node!!");

        } else {

            if (q -> tail == NULL) {
                q -> head = q -> tail = new_node;
            } else {
                q -> tail -> next = new_node;
                q -> tail = new_node;
            }
        }
    }
}

node *peek(queue *q) {
    return q -> head;
}

void poll(queue *q) {
    if (q != NULL && q -> head != NULL) {
        node *polled = q -> head;
        if (q -> head -> next == NULL) {
            __reset(q);

        } else {
            q -> head = q -> head -> next;
        }
        free(polled);
    }
}

size_t size(queue *q) {
    size_t l = 0;
    node *tmp = q -> head;

    while (tmp != NULL) {
        l ++;
        tmp = tmp -> next;
    }
    return l;
}

void listq(queue *q) {
    node *tmp = q -> head;
    printf("\nDisplay queue values start");

    while (tmp != NULL) {
        printf("\n\t%s", tmp -> value);
        tmp = tmp -> next;
    }
    printf("\nEnd");
}

node *__create_new_node(const char *value) {
    node *new_node = malloc(sizeof(node));
    if (new_node != NULL) {
        strncpy(new_node -> value, value, MAX_SIZE_VALUE);
        new_node -> next = NULL;
    }
    return new_node;
}

void __init(queue *q) {
    __reset(q);
}

void __reset(queue *q) {
    q -> head = NULL;
    q -> tail = NULL;
}

