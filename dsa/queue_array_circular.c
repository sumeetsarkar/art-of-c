#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

typedef struct {
    int32_t *values;
    uint32_t capacity;
    uint32_t size;
    uint32_t front;
    uint32_t rear;
} cq_i;

cq_i *cq_i_create(uint32_t capacity);
void cq_i_destroy(cq_i *q);
void cq_i_push(cq_i *q, int32_t value);
int32_t cq_i_pop(cq_i *q);
void cq_i_print(cq_i *q);

int main(int argc, char **argv) {
    cq_i *q = cq_i_create(5);
    cq_i_print(q);

    cq_i_pop(q);
    cq_i_push(q, 10);
    cq_i_push(q, 20);
    cq_i_push(q, 30);
    cq_i_print(q);

    cq_i_pop(q);
    cq_i_pop(q);
    cq_i_print(q);

    cq_i_push(q, 40);
    cq_i_print(q);

    cq_i_push(q, 50);
    cq_i_print(q);

    cq_i_pop(q);
    cq_i_print(q);

    cq_i_push(q, 60);
    cq_i_push(q, 70);
    cq_i_push(q, 80);
    cq_i_print(q);

    cq_i_pop(q);
    cq_i_print(q);

    cq_i_push(q, 90);
    cq_i_print(q);

    cq_i_push(q, 100);
    cq_i_print(q);

    cq_i_pop(q);
    cq_i_print(q);

    cq_i_destroy(q);
    q = NULL;
    return EXIT_SUCCESS;
}

cq_i *cq_i_create(uint32_t capacity) {
    cq_i *q = malloc(sizeof(*q));
    q -> values = calloc(capacity, sizeof(uint32_t));
    q -> capacity = capacity;
    q -> front = 0;
    q -> rear = 0;
    q -> size = 0;
    return q;
}

void cq_i_destroy(cq_i *q) {
    q -> capacity = 0;
    q -> size = 0;
    q -> front = 0;
    q -> rear = 0;
    free(q -> values);
    free(q);
}

void cq_i_push(cq_i *q, int32_t value) {
    if (q -> size == q -> capacity) {
        printf("cq_i size overflow, cannot push: %d\n", value);
        return;
    }
    uint32_t next_rear = (q -> rear + 1) % q -> capacity;
    q -> values[next_rear] = value;
    q -> rear = next_rear;
    if (q -> size == 0)
        q -> front = q -> rear;
    q -> size += 1;
    if (DEBUG)
        printf("pushed: %d\n", q -> values[q -> rear]);
}

int32_t cq_i_pop(cq_i *q) {
    if (q -> size == 0) {
        printf("cq_i size underflow\n");
        return INT32_MIN;
    }
    int32_t popped = q -> values[q -> front];
    uint32_t next_front = (q -> front + 1) % q -> capacity;
    q -> values[q -> front] = 0;
    q -> front = next_front;
    q -> size -= 1;
    if (DEBUG)
        printf("popped: %d\n", popped);
    return popped;
}

void cq_i_print(cq_i *q) {
    printf("Queue values---\n");
    for (uint32_t i = 0; i < q -> capacity; i++) {
        printf("%d ", q -> values[i]);
    }
    printf("\nEnd---\n");
}

