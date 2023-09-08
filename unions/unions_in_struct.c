#include <stdio.h>
#include <stdlib.h>

typedef enum { UT_INT = 1, UT_CHAR = 2 } utype;

typedef struct {
    utype type;
    union {
        int i_data;
        char *c_data;
    } data;
} data_node;

void print_data_node(data_node *dn);

int main(int argc, char **argv) {
    data_node dn1;
    dn1.type = UT_INT;
    dn1.data.i_data = 99;
    print_data_node(&dn1);

    data_node dn2;
    dn2.type = UT_CHAR;
    dn2.data.c_data = "test-data";
    print_data_node(&dn2);

    return EXIT_SUCCESS;
}

void print_data_node(data_node *dn) {
    if (dn -> type == UT_INT) {
        printf("data = %d\n", dn -> data.i_data);
    } else if (dn -> type == UT_CHAR) {
        printf("data = %s\n", dn -> data.c_data);
    }
}

