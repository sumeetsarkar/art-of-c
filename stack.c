#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_VALUE 32

typedef struct node {
    char value[MAX_SIZE_VALUE];
    struct node *next;
} node;

void push(const char *value);
node *top();
node *pop();
void list();
node *__create_new_node(const char *value);
void __reset();
void __init();

node *head;

int main(int argc, char **argv) {
    __init();

    push("red");
    push("green");
    push("blue");
    list();

    printf("\nPopping %s", pop() -> value);
    printf("\nPopping %s", pop() -> value);
    list();

    printf("\nTop %s", top() -> value);
    printf("\nPopping %s", pop() -> value);
    list();

    push("cyan");
    push("magenta");
    push("yellow");
    list();
    return 0;
}

void push(const char *value) {
    node *new_node = __create_new_node(value);

    if (new_node != NULL) {
        if (head != NULL) {
            new_node -> next = head;
        }
        head = new_node;
    }
}

node *pop() {
    node *popped;
    if (head != NULL) {
        popped = head;
        head = head -> next;
    }
    return popped;
}

node *top() {
    return head;
}

void list() {
    node *tmp = head;
    printf("\nDisplay stack values start");

    while (tmp != NULL) {
        printf("\n\t%s", tmp -> value);
        tmp = tmp -> next;
    }
    printf("\nEnd");
}

void __reset() {
    head = NULL;
}

void __init() {
    __reset();
}

node *__create_new_node(const char *value) {
    node *new_node = malloc(sizeof(node));
    if (new_node != NULL) {
        strcpy(new_node -> value, value);
        new_node -> next = NULL;
    }
    return new_node;
}

