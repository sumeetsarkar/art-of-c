#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int capacity;
    int size;
    int *arr;
} heap;

int __root_index(int i);
int __left_child_index(int i);
int __right_child_index(int i);

int __has_root(heap *h, int i);
int __has_left_child(heap *h, int i);
int __has_right_child(heap *h, int i);

int __root(heap *h, int i);
int __left_child(heap *h, int i);
int __right_child(heap *h, int i);

int __has_capacity(heap *h);
void __heapify_up(heap *h);
void __heapify_down(heap *h);

heap *new_heap(int capacity);
void free_heap(heap *h);
int size(heap *h);
void push(heap *h, int value);
int top(heap *h);
int pop(heap *h);

int main(int argc, char **argv) {
    heap *h = new_heap(10);
    push(h, 12);
    push(h, 5);
    push(h, 2);
    push(h, 9);
    push(h, 8);
    push(h, 3);
    push(h, 100);
    push(h, -1);
    push(h, 0);

    printf("\nTop: %d", top(h));
    printf("\n");

    while (size(h) > 0) {
        printf("%d  ", pop(h));
    }

    push(h, 5);
    push(h, 9);
    push(h, 8);
    push(h, -1);
    push(h, 0);
    push(h, -100);
    printf("\n");

    while (size(h) > 0) {
        printf("%d  ", pop(h));
    }
    
    free_heap(h);
    printf("\n");
    return EXIT_SUCCESS;
}

heap *new_heap(int capacity) {
    heap *h = malloc(sizeof(heap));
    if (h == NULL)
        return NULL;

    h -> capacity = capacity;
    h -> size = 0;
    h -> arr = calloc(sizeof(int), h -> capacity);

    if (h -> arr == NULL) {
        h -> capacity = 0;
        free(h);
        h = NULL;
    }
    return h;
}

void free_heap(heap *h) {
    if (h == NULL)
        return;

    if (h -> arr != NULL) {
        free(h -> arr);
    }

    h -> size = 0;
    h -> capacity = 0;
    h -> arr = NULL;
    free(h);
    h = NULL;
}

int size(heap *h) {
    if (h == NULL || h -> arr == NULL)
        return 0;
    return h -> size;
}

void push(heap *h, int value) {
    if (__has_capacity(h) == 0)
        return;

    h -> arr[h -> size] = value;
    h -> size += 1;
    __heapify_up(h);
}

int top(heap *h) {
    return h -> arr[0];
}

int pop(heap *h) {
    int popped_value = h -> arr[0];

    h -> size -= 1;
    h -> arr[0] = h -> arr[h -> size];
    h -> arr[h -> size] = 0;
    __heapify_down(h);
    return popped_value;
}

int __root_index(int i) {   
    return (i - 1) / 2;
}

int __left_child_index(int i) {
    return 2 * i + 1;
}

int __right_child_index(int i) {
    return 2 * i + 2;
}

int __has_root(heap *h, int i) {
    if (i == 0)
        return 0;
    int index = __root_index(i);
    return index > -1 && index < h -> size;
}

int __has_left_child(heap *h, int i) {
    int index = __left_child_index(i);
    return index > -1 && index < h -> size;
}

int __has_right_child(heap *h, int i) {
    int index = __right_child_index(i);
    return index > -1 && index < h -> size;
}

int __root(heap *h, int i) {
    return h -> arr[__root_index(i)];
}

int __left_child(heap *h, int i) {
    return h -> arr[__left_child_index(i)];
}

int __right_child(heap *h, int i) {
    return h -> arr[__right_child_index(i)];
}

int __has_capacity(heap *h) {
    if (h -> size == 0) {
        return -1;
    } else if (h -> size >= h -> capacity) {
        return 0;
    } else {
        return 1;
    }
}

void __heapify_up(heap *h) {
    int i = h -> size - 1;

    while (__has_root(h, i)) {
        int root_value = __root(h, i);
        int root_index = __root_index(i);

        if (h -> arr[i] < root_value) {
            int swap = h -> arr[i];
            h -> arr[i] = root_value;
            h -> arr[root_index] = swap;
        }
        i = root_index;
    }
}

void __heapify_down(heap *h) {
    int i = 0;

    while (__has_left_child(h, i)) {
        int small_index = __left_child_index(i);
        int small_value = __left_child(h, i);

        if (__has_right_child(h, i) && __right_child(h, i) < small_value) {
            small_index = __right_child_index(i);
            small_value = __right_child(h, i);
        }

        if (small_value < h -> arr[i]) {
            int swap = h -> arr[i];
            h -> arr[i] = small_value;
            h -> arr[small_index] = swap;
        }
        i = small_index;
    }
}

