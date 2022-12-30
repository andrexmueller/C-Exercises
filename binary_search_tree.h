#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <stddef.h>

typedef struct node node_t;

struct node {
   node_t *right;
   node_t *left;
   int data;
};

/*                helper methods                */
node_t *init_node(int data);
void insert_node(node_t *node, int data);
void tree_traverse(node_t *node, int *array, int *index);

/*                 main methods                 */
node_t *build_tree(int *tree_data, size_t tree_data_len);
void free_tree(node_t *tree);
int *sorted_data(node_t *tree);

#endif