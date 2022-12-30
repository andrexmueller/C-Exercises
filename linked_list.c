#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

#include "linked_list.h"

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

typedef struct list List;
typedef struct list_node Node;
int is_empty(List *ll);
Node *node_create(ll_data_t data);


struct list *list_create(void) {
    List *ll = malloc(sizeof(List));
    ll->first = NULL;
    ll->last = NULL;
    return ll;
}


size_t list_count(const struct list *list) {
    size_t counter = 0;
    Node *node = list->first;
    while (node) {
        node = node->next;
        counter++;
    }
    return counter;
}


void list_push(struct list *list, ll_data_t item_data) {
    Node *node = node_create(item_data);
    if (list->first == NULL) {
        list->first = node;
        list->last = node;
        return;
    }
    node->prev = list->last;
    list->last->next = node;
    list->last = node;
    return;
}


ll_data_t list_pop(struct list *list) {
    ll_data_t data = list->last->data;
    Node *tmp = list->last;
    if (list->first == list->last) {
        list->first = NULL;
        list->last = NULL;    
    } else {
        list->last = list->last->prev;
        list->last->next = NULL;
    }
    free(tmp);
    return data;
}


void list_unshift(struct list *list, ll_data_t item_data) {
    if (is_empty(list)) 
        list_push(list, item_data);
    else {
        Node *node = node_create(item_data);
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }
    return;
}


ll_data_t list_shift(struct list *list) {
    ll_data_t data = list->first->data;
    Node *tmp = list->first;
    if (list->first == list->last) {
        list->first = NULL;
        list->last = NULL;    
    } else {
        list->first = list->first->next;
        list->first->prev = NULL;
    }
    free(tmp);
    return data;
}


void list_delete(struct list *list, ll_data_t data) {
    Node *node = list->first;
    while (node) {
        if (node->data == data) {
            if (node == list->first && node == list->last) {
                list->first = NULL;
                list->last = NULL;
            } else if (node == list->first) {
                list_shift(list);
            } else if (node == list->last) {
                list_pop(list);
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            break;
        }
        node = node->next;
    }
    free(node);
    return;
}


void list_destroy(struct list *list) {
    Node *node = list->first;
    Node *tmp = NULL;
    while (node) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    list = NULL;
    //free(list);
}


/////////// Helpert functions /////////////////

int is_empty(List* ll) {
    return ll->first == NULL;
}


void print_list(List* ll) {
    if (ll == NULL) printf("\nNo list\n");
    if (is_empty(ll)) printf("\nEmpty List\n");
    Node *node = ll->first;
    while(node) {
        printf("\n -> %d", node->data);
        node = node->next;
    }
    printf("\n");
    return;
}


Node *node_create(ll_data_t data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void TEST_ASSERT_EQUAL(ll_data_t expected, ll_data_t ans) {
    if (expected == ans) printf("TESTE PASSED!\n");
    else printf("TESTE FAILED!\n");
}


//////////////////////////////////////////////////////
int main(int argc, char *argv[]) {


    struct list *list = NULL;
    list = list_create();
    if (list) {
      list_destroy(list);
      list = NULL;
   }
         
         
    // list_push(list, 7);
    // TEST_ASSERT_EQUAL(7, list_pop(list));

    // list_push(list, 11);
    // list_push(list, 13);
    // TEST_ASSERT_EQUAL(13, list_pop(list));
    // TEST_ASSERT_EQUAL(11, list_pop(list));

    // list_push(list, 17);
    // TEST_ASSERT_EQUAL(17, list_shift(list));

    // list_unshift(list, 23);
    // list_unshift(list, 5);
    // TEST_ASSERT_EQUAL(5, list_shift(list));
    // TEST_ASSERT_EQUAL(23, list_shift(list));

    // list_push(list, 1);
    // list_push(list, 2);
    // TEST_ASSERT_EQUAL(2, list_pop(list));
    // list_push(list, 3);
    // TEST_ASSERT_EQUAL(1, list_shift(list));
    // list_unshift(list, 4);
    // list_push(list, 5);
    // TEST_ASSERT_EQUAL(4, list_shift(list));
    // TEST_ASSERT_EQUAL(5, list_pop(list));
    // TEST_ASSERT_EQUAL(3, list_shift(list));

    // TEST_ASSERT_EQUAL(0, list_count(list));

    // list_push(list, 37);
    // list_push(list, 1);
    // TEST_ASSERT_EQUAL(2, list_count(list));

    // list_push(list, 31);
    // TEST_ASSERT_EQUAL(1, list_count(list));
    // list_unshift(list, 43);
    // TEST_ASSERT_EQUAL(2, list_count(list));
    // list_shift(list);
    // TEST_ASSERT_EQUAL(1, list_count(list));
    // list_pop(list);
    // TEST_ASSERT_EQUAL(0, list_count(list));

    // list_push(list, 41);
    // list_push(list, 59);
    // list_pop(list);
    // list_pop(list);
    // list_push(list, 47);
    // TEST_ASSERT_EQUAL(1, list_count(list));
    // TEST_ASSERT_EQUAL(47, list_pop(list));

    // list_push(list, 41);
    // list_push(list, 59);
    // list_shift(list);
    // list_shift(list);
    // list_push(list, 47);
    // TEST_ASSERT_EQUAL(1, list_count(list));
    // TEST_ASSERT_EQUAL(47, list_shift(list));


    // list_push(list, 61);
    // list_delete(list, 61);
    // TEST_ASSERT_EQUAL(0, list_count(list));

    // list_push(list, 71);
    // list_push(list, 83);
    // list_push(list, 79);
    // list_delete(list, 83);
    // TEST_ASSERT_EQUAL(2, list_count(list));
    // TEST_ASSERT_EQUAL(79, list_pop(list));
    // TEST_ASSERT_EQUAL(71, list_shift(list));

    // list_push(list, 71);
    // list_push(list, 83);
    // list_push(list, 79);
    // list_delete(list, 83);
    // TEST_ASSERT_EQUAL(2, list_count(list));
    // TEST_ASSERT_EQUAL(71, list_shift(list));
    // TEST_ASSERT_EQUAL(79, list_shift(list));

    // list_push(list, 97);
    // list_push(list, 101);
    // list_delete(list, 97);
    // TEST_ASSERT_EQUAL(1, list_count(list));
    // TEST_ASSERT_EQUAL(101, list_pop(list));

//     list_push(list, 97);
//     list_push(list, 101);
//     list_delete(list, 101);
//     TEST_ASSERT_EQUAL(1, list_count(list));
//     TEST_ASSERT_EQUAL(97, list_pop(list));

    // list_push(list, 89);
    // list_delete(list, 103);
    // TEST_ASSERT_EQUAL(1, list_count(list));

//    list_push(list, 73);
//    list_push(list, 9);
//    list_push(list, 9);
//    list_push(list, 107);
//    list_delete(list, 9);
//    TEST_ASSERT_EQUAL(3, list_count(list));
//    TEST_ASSERT_EQUAL(107, list_pop(list));
//    TEST_ASSERT_EQUAL(9, list_pop(list));
//    TEST_ASSERT_EQUAL(73, list_pop(list));


    return 0;
}


