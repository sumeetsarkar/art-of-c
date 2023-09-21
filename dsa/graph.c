#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_VERTICES 5

typedef struct {
    uint32_t u;
    uint32_t v;
    uint32_t w;
} graph_edge;

typedef struct graph_node {
    uint32_t u;
    uint32_t v;
    uint32_t w;
    struct graph_node *next;
} graph_node;

// Maps node u as index in *vertices
// Eg: edge (0, 2) is 0th index of *vertices with graph_node (0, 2)
typedef struct {
    graph_node *vertices[NUM_VERTICES];
} graph;

graph *graph_create(void);
void graph_destroy(graph *g);
void graph_add_node(graph *g, graph_edge e);
void graph_print(graph *g);

int main(int argc, char **argv) {
    // Basic directed graph
    graph_edge edges[] = {
        { .u = 0, .v = 1, .w = 10 },
        { .u = 1, .v = 2, .w = 20 },
        { .u = 2, .v = 1, .w = 9  },
        { .u = 2, .v = 0, .w = 5  },
        { .u = 3, .v = 2, .w = 44 },
    };
    uint32_t len_edges = sizeof(edges) / sizeof(edges[0]);
    graph *g = graph_create();

    for (uint32_t i = 0; i < len_edges; i++) {
        graph_add_node(g, edges[i]);
    }
    graph_print(g);
    graph_destroy(g);
    return EXIT_SUCCESS;
}

void graph_add_node(graph *g, graph_edge e) {
    uint32_t u = e.u;
    uint32_t v = e.v;
    uint32_t w = e.w;

    graph_node *gnode = malloc(sizeof(graph_node));
    gnode -> u = u;
    gnode -> v = v;
    gnode -> w = w;
    gnode -> next = g -> vertices[gnode -> u];
    g -> vertices[gnode -> u] = gnode;
}

void graph_print(graph *g) {
    for (uint32_t i = 0; i < NUM_VERTICES; i++) {
        graph_node *gnode = g -> vertices[i];
        while (gnode) {
            printf("(%d -> %d w:%d) ", gnode -> u, gnode -> v, gnode -> w);
            gnode = gnode -> next;
        }
        printf("\n");
    }
}

graph *graph_create(void) {
    graph *g = malloc(sizeof(graph));
    for (uint32_t i = 0; i < NUM_VERTICES; i++)
        g -> vertices[i] = NULL;
    return g;
}

void graph_destroy(graph *g) {
    for (uint32_t i = 0; i < NUM_VERTICES; i++) {
        graph_node *prev = g -> vertices[i];
        while (prev) {
            graph_node *tmp = prev -> next;
            free(prev);
            prev = tmp;
        }
    }
    free(g);
}

