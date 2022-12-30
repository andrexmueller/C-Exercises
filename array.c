#include <stdio.h>
#include <stdlib.h>


typedef struct node_t {
    struct node_t *next, *prev;
    void *data;
} node_t;


node_t *new_node(void *data) {
    node_t *node = malloc(sizeof(node));
    node->next = NULL;
    node->prev = NULL;
    node->data = data;
    return node;
}

int main()
{

    printf("\n=====================\n");


    int val = 10;
    double x = 10.0;
    char s[10] = "abcdefgh";
    node_t *head = new_node(&val);
    node_t *n1 = new_node(&x);
    node_t *n2 = new_node(s);

    printf(" %d %f %s\n", *(int*)head->data, *(double*)n1->data, n2->data);

    printf("\n=====================\n");


    return 0;
}