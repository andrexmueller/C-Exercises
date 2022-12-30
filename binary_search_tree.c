/*
Exercism
Binary Search Tree
https://exercism.org/tracks/c/exercises/binary-search-tree/edit
*/

#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

/* ---- helper methods ----*/

node_t *init_node(int data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_node(node_t *node, int data) {
    if (data <= node->data) {
        if (!node->left) {
            node_t *new_node = init_node(data);
            node->left = new_node;
        } else {
            insert_node(node->left, data);
        }
    } else {
        if (!node->right) {
            node_t *new_node = init_node(data);
            node->right = new_node;
        } else {
            insert_node(node->right, data);
        }
    }
}

void tree_traverse(node_t *node, int *array, int *index) {
    if (!node) return;
    tree_traverse(node->left, array, index);
    array[*index] = node->data;
    *index += 1;
    tree_traverse(node->right, array, index);
}

/* ---- main methods ----*/

node_t *build_tree(int *tree_data, size_t tree_data_len) {
    node_t *root = init_node(tree_data[0]);
    size_t i = 0;
    for (i = 1; i < tree_data_len; i++) {
        insert_node(root, tree_data[i]);
    }
    return root;
}

int *sorted_data(node_t *tree) {
    int *arr = malloc(sizeof(int) * 10);
    int index = 0;
    tree_traverse(tree, arr, &index);
    return arr;
}

void free_tree(node_t *tree) {
    if (!tree) return;
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}





int main() {

    int tree_data[] = { 6, 5, 7, 1, 7, 0 , 11, -2, 77, 16};
    node_t *tree = build_tree(tree_data, 10);

    // int *foo;
    // int index = 0;
    // tree_traverse(tree, foo, &index);


    printf("\n=====================================\n");
    int *arr;
    arr = sorted_data(tree);
    printf("\n=====================================\n");
    //int i;
    for (int i=0; i<10;i++) printf(" >> %d ", arr[i]);
    printf("\n=====================================\n");
    free_tree(tree);
}
