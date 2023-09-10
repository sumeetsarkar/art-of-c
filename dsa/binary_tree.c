#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node;

typedef struct binary_tree {
    node *root;
} binary_tree;

void init(binary_tree *tree);
node *create_node(int value);
node *create_node_c(int value, node *left, node *right);
void print_tree_indent(node *node, int level);

int main(int argc, char **argv) {
    binary_tree tree;

    init(&tree);
    tree.root = create_node_c(4, 
                    // left
                    create_node_c(5,
                        // left
                        create_node_c(1, NULL, NULL),
                        // right
                        create_node_c(9, NULL, NULL)
                    ),
                    // right
                    create_node_c(6, 
                        // left
                        create_node_c(10,
                            // left                      
                            create_node_c(8, NULL, NULL),
                            // right
                            NULL),
                        // right
                        create_node_c(3, NULL, NULL)
                    )
                );
    print_tree_indent(tree.root, 0);
    printf("\n");

    binary_tree tree2;
    init(&tree2);
    tree.root = create_node(10);
    tree.root -> left =  create_node(12);
    tree.root -> right = create_node(7);
    tree.root -> left -> left = create_node(4);
    tree.root -> left -> right = create_node(2);
    tree.root -> right -> left = create_node(5);
    tree.root -> right -> right = create_node(11);
    print_tree_indent(tree.root, 0);

    printf("\n");
    return EXIT_SUCCESS;
}

void init(binary_tree *tree) {
    tree -> root = NULL;
}

node *create_node(int value) {
    return create_node_c(value, NULL, NULL);
}

node *create_node_c(int value, node *left, node *right) {
    node *new_node = malloc(sizeof(node));
    new_node -> value = value;
    new_node -> left = left;
    new_node -> right = right;
    return new_node;
}

void print_tree_indent(node *node, int level) {
    if (node != NULL) {
        for (int i = 0; i < level; i++) {
            printf("---");
        }
        printf(">[%d]\n", node -> value);
        level += 1;
        print_tree_indent(node -> left, level);
        print_tree_indent(node -> right, level);
    }
}

