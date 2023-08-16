#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_VALUE 32

typedef struct node {
    char value[MAX_SIZE_VALUE];
    struct node *next;
} node;

typedef struct stack {
    node *head;
} stack;

void push(stack *s, const char *value);
void pop(stack *s);
node *top(stack *s);
size_t size(stack *s);
void list(stack *s);
node *__create_new_node(const char *value);
void __reset(stack *s);
void __init(stack *s);

int main(int argc, char **argv) {
    stack colors;
    __init(&colors);

    push(&colors, "red");
    push(&colors, "green");
    push(&colors, "blue");
    list(&colors);
    printf("\nSize: %ld", size(&colors));

    pop(&colors);
    pop(&colors);
    list(&colors);
    printf("\nSize: %ld", size(&colors));

    printf("\nTop %s", top(&colors) -> value);
    pop(&colors);
    list(&colors);
    printf("\nSize: %ld", size(&colors));

    push(&colors, "cyan");
    push(&colors, "magenta");
    push(&colors, "yellow");
    list(&colors);
    printf("\nSize: %ld", size(&colors));

    printf("\n");
    return 0;
}

void push(stack *s, const char *value) {
    node *new_node = __create_new_node(value);

    if (new_node != NULL && s != NULL) {
        if (s -> head != NULL) {
            new_node -> next = s -> head;
        }
        s -> head = new_node;
    }
}

void pop(stack *s) {
    if (s != NULL && s -> head != NULL) {
        node *popped = s -> head;
        s -> head = s -> head -> next;
        free(popped);
    }
}

node *top(stack *s) {
    return s -> head;
}

size_t size(stack *s) {
    size_t l = 0;
    node *tmp = s -> head;

    while (tmp != NULL) {
        l ++;
        tmp = tmp -> next;
    }
    return l;
}

void list(stack *s) {
    node *tmp = s -> head;
    printf("\nDisplay stack values start");

    while (tmp != NULL) {
        printf("\n\t%s", tmp -> value);
        tmp = tmp -> next;
    }
    printf("\nEnd");
}

void __reset(stack *s) {
    s -> head = NULL;
}

void __init(stack *s) {
    __reset(s);
}

node *__create_new_node(const char *value) {
    node *new_node = malloc(sizeof(node));
    if (new_node != NULL) {
        strncpy(new_node -> value, value, MAX_SIZE_VALUE);
        new_node -> next = NULL;
    }
    return new_node;
}

