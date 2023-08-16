#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_VALUE 32

typedef struct node {
    char value[MAX_SIZE_VALUE];
    struct node *next;
} node;

node *head, *tail;

void push(const char *value);
node *poll();
node *peek();
void listq();
node *__create_new_node(const char *value);
void __init();
void __reset();

int main(int argc, char **argv) {
    __init();

    push("red");
    push("green");
    push("blue");
    listq();

    printf("\nPolled: %s", poll() -> value);
    listq();

    printf("\nPolled: %s", poll() -> value);
    listq();

    printf("\nPeeked: %s", peek() -> value);

    push("cyan");
    push("magenta");
    push("yellow");
    listq();

    return 0;
}

void push(const char *value) {
    if (value != NULL) {

        node *new_node = __create_new_node(value);
        if (new_node == NULL) {
            printf("\n!!Unable to create new node!!");

        } else {
            if (tail == NULL) {
                head = tail = new_node;
            } else {
                tail -> next = new_node;
                tail = new_node;
            }
        }
    }
}

node *peek() {
    return head;
}

node *poll() {
    node *polled = NULL;

    if (head != NULL) {
        polled = head;
        if (head -> next == NULL) {
            __reset();

        } else {
            head = head -> next;
        }
    }
    return polled;
}

void listq() {
    node *tmp = head;
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
        strcpy(new_node -> value, value);
        new_node -> next = NULL;
    }
    return new_node;
}

void __init() {
    __reset();
}

void __reset() {
    head = tail = NULL;
}

