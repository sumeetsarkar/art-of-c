#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE_LEN 10

typedef void (free_function) (void *o);
typedef void (value_function) (void *o);

typedef struct {
    void *value;
    free_function *free_fn;
    value_function *value_fn;
} node;

node *newnode(void *o, free_function *free_fn, value_function *value_fn);
// both destroy 1 and 2 effectively take free function arguments which are
// of same function signatures
void destroy_node_1(node *n, void (*my_free_function) (void *o));
void destroy_node_2(node *n, free_function free_fn);
void process_node(node *n, value_function value_fn);

void free_object(void *o);
void display_object(void *o);

int main(int argc, char **argv) {
    node *n1 = newnode(strndup("Hello", MAX_VALUE_LEN), NULL, NULL);
    process_node(n1, display_object);
    destroy_node_1(n1, free_object);

    free_function *ff = free_object;
    value_function *vf = display_object;
    node *n2 = newnode(strndup("Mom!", MAX_VALUE_LEN), ff, vf);
    process_node(n2, NULL);
    destroy_node_2(n2, NULL);

    // next to lines are similar as strdup operation done previously
    char *value = malloc(MAX_VALUE_LEN * sizeof(char));
    strncpy(value, "& World!", MAX_VALUE_LEN);
    // the malloc.h free function also works here because of matching signatures
    node *n3 = newnode(value, free, vf);
    process_node(n1, vf); 
    destroy_node_2(n3, free);

    return EXIT_SUCCESS;
}

node *newnode(void *o, free_function *free_fn, value_function *value_fn) {
    node *n = malloc(sizeof(node));
    n -> value = o;
    n -> free_fn = free_fn;
    n -> value_fn = value_fn;
    return n;
}

void destroy_node_1(node *n, free_function free_fn) {
    if (free_fn == NULL) {
        free_fn = n -> free_fn;
    }
    free_fn(n -> value);
    n -> value = NULL;
    n -> free_fn = NULL;
    n -> value_fn = NULL;
    free(n);
    n = NULL;
}

void destroy_node_2(node *n, void (*free_fn) (void *o)) {
    if (free_fn == NULL) {
        free_fn = n -> free_fn;
    }
    free_fn(n -> value);
    n -> value = NULL;
    n -> free_fn = NULL;
    n -> value_fn = NULL;
    free(n);
    n = NULL;
}

void free_object(void *o) {
    free(o);
    o = NULL;
}

void process_node(node *n, value_function value_fn) {
    if (value_fn != NULL) {
        value_fn(n -> value);
    } else if (n -> value_fn != NULL) {
        n -> value_fn(n -> value);
    }
}

void display_object(void *o) {
    printf("%s\n", (char*)o);
}

