/*
 *   LeetCode
 *   Given the head of a linked list, remove the nth node from the end of the list and return its head.
 *   https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    // list has only one node
    if (head->next == NULL) return NULL;
    
    struct ListNode *pt1, *pt2, *tmp;
    pt1 = head;
    pt2 = NULL;
    tmp = NULL;

    // moving two pointes. pt2 points to the prev node 
    // which is about to be removed
    while (pt1) {
        pt1 = pt1->next;
        if (n == 0) pt2 = head;
        if (n < 0) pt2 = pt2->next;
        n--;
    }

    // if pt2 still points to NULL, ie, did not move, 
    // the head is the one to be removed
    if (!pt2) {
        tmp = head->next;
        head->next = NULL;
        head = tmp;
    } 
    // pt2 has moved to nth-1 node. we must remove pt2.next
    else { 
        
        tmp = pt2->next;
        pt2->next = tmp->next;
        tmp->next = NULL;
    }
    

    
    free(tmp);
    
    return head;
}

void print(struct ListNode *head) {
    printf("\n[");
    while (head) {
        printf("%d, ", head->val);
        head = head->next;
    }
    printf("\b\b] \n");
}


int main() {
    
    struct ListNode head = {1, NULL};
    struct ListNode n1 = {2, NULL};
    struct ListNode n2 = {3, NULL};
    struct ListNode n3 = {4, NULL};
    struct ListNode n4 = {5, NULL};

    head.next = &n1;
    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    
    print(&head);

    head = *removeNthFromEnd(&head, 2);

    //removeNthFromEnd(&head, 2);

    print(&head);

    


    
}