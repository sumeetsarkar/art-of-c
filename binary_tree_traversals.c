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
void print_tree_i(node *root, int level);
void preorder_r(node *root);
void inorder_r(node *root);
void postorder_r(node *root);

int main(int argc, char **argv) {
    binary_tree tree;

    tree.root = create_node(4);

    tree.root -> left =  create_node(5);
    tree.root -> left -> left = create_node(1);
    tree.root -> left -> right = create_node(9);

    tree.root -> right = create_node(6);
    tree.root -> right -> left = create_node(10);
    tree.root -> right -> left -> left = create_node(8);
    tree.root -> right -> right = create_node(3);

    print_tree_i(tree.root, 0);

    printf("\nPreorder:\t");
    preorder_r(tree.root);

    printf("\nInorder:\t");
    inorder_r(tree.root);

    printf("\nPostorder:\t");
    postorder_r(tree.root);

    printf("\n");
    return EXIT_SUCCESS;
}

void init(binary_tree *tree) {
    tree -> root = NULL;
}

node *create_node(int value) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("\n!!Unable to create new node!!");
    } else {
        new_node -> value = value;
        new_node -> left = NULL;
        new_node -> right = NULL;
    }
    return new_node;
}

void preorder_r(node *root) {
    if (root != NULL) {
        printf("%d  ", root -> value);
        preorder_r(root -> left);
        preorder_r(root -> right);
    }
}

void inorder_r(node *root) {
    if (root != NULL) {
        inorder_r(root -> left);
        printf("%d  ", root -> value);
        inorder_r(root -> right);
    }
}

void postorder_r(node *root) {
    if (root != NULL) {
        postorder_r(root -> left);
        postorder_r(root -> right);
        printf("%d  ", root -> value);
    }
}

void print_tree_i(node *root, int level) {
    if (root != NULL) {
        for (int i = 0; i < level; i++) {
            printf("---");
        }
        level++;
        printf(">[%d]\n", root -> value);
        print_tree_i(root -> left, level);
        print_tree_i(root -> right, level);
    }
}
