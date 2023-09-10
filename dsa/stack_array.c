#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// only for positive integers
typedef struct stack {
    int items[MAX_SIZE];
    int size;
} stack;

void init(stack *st);
void push(stack *st, int value);
int pop(stack *st);
int top(stack *st);
int size(stack *st);
void display(stack *st);

int main(int argc, char **argv) {

    stack stack1;
    init(&stack1);

    push(&stack1, 8);
    push(&stack1, 4);
    push(&stack1, 1);
    push(&stack1, 2);
    push(&stack1, 6);
    push(&stack1, 5);
    push(&stack1, 9);
    push(&stack1, 7);
    push(&stack1, 3);
    push(&stack1, 2);
    push(&stack1, 10);
    push(&stack1, 11);
    display(&stack1);

    printf("\nSize  : %d", size(&stack1));
    printf("\nTop   : %d", top(&stack1));
    printf("\nPopped: %d", pop(&stack1));
    printf("\nTop   : %d", top(&stack1));
    printf("\nPopped: %d", pop(&stack1));
    printf("\nTop   : %d", top(&stack1));
    printf("\nPopped: %d", pop(&stack1));
    printf("\nSize  : %d", size(&stack1));
    printf("\nTop   : %d", top(&stack1));
    display(&stack1);

    printf("\nTop   : %d", top(&stack1));
    printf("\nPopped: %d", pop(&stack1));
    printf("\nSize  : %d", size(&stack1));
    display(&stack1);

    printf("\nPopped: %d", pop(&stack1));
    printf("\nPopped: %d", pop(&stack1));
    printf("\nPopped: %d", pop(&stack1));
    printf("\nPopped: %d", pop(&stack1));
    printf("\nPopped: %d", pop(&stack1));
    display(&stack1);

    printf("\nPopped: %d", pop(&stack1));
    display(&stack1);

    printf("\nPopped: %d", pop(&stack1));
    printf("\nPopped: %d", pop(&stack1));

    printf("\n");
    return EXIT_SUCCESS;
}

void init(stack *st) {
    st -> size = -1;
    for (int i = 0; i < MAX_SIZE; i++) {
        st -> items[i] = -1;
    }
}

void push(stack *st, int value) {
    if (size(st) < MAX_SIZE) {
        st -> size += 1;
        st -> items[st -> size] = value;
    } else {
        printf("\n!!Stack overflow!! Cannot push %d", value);
    }
}

int pop(stack *st) {
    int ret_val = top(st);
    if (ret_val > -1) {
        st -> items[st -> size] = -1;
        st -> size -= 1;
    } else {
        printf("\n!!Stack underflow!!");
    }
    return ret_val;
}

int top(stack *st) {
    int ret_val = -1;
    if (size(st) > 0) {
        ret_val = st -> items[st -> size];
    }
    return ret_val;
}

int size(stack *st) {    
    return st -> size + 1;
}

void display(stack *st) {
    printf("\n\n----start\n");
    for (int i = 0; i < size(st); i++) {
        printf("%d  ", st -> items[i]);
    }
    printf("\nend----\n");
}

