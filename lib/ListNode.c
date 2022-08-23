#include <stdlib.h>
#include <stdio.h>
#include "ListNode.h"

/**
 * @brief Create linked list of ListNode structs
 * 
 * @param nums Array of values to turn into a list
 * @param size Size of list (size of nums)
 * @return struct ListNode*: head of list
 */
struct ListNode * createList(int nums[], int size) {
    struct ListNode r;
    r.val = 0;
    r.next = NULL;

    struct ListNode * node = &r;

    for (int i = 0; i < size; i++) {
        node->next = malloc(sizeof(struct ListNode));
        node->next->val = nums[i];
        node->next->next = NULL;
        node = node->next;
    }

    struct ListNode * head = r.next;
    return head;
}

/**
 * @brief Prints the values in a linked list of ListNode structs
 * 
 * @param head Pointer to head of list
 */
void printList(struct ListNode * head) {
    while (head != NULL) {
        printf("%d,", head->val);
        head = head->next;
    }
    printf("\n");
}

/**
 * @brief Checks whether two linked lists of ListNode objects are equal
 * 
 * @param head1 Head of first list
 * @param head2 Head of second list
 * @return true 
 */
bool assertListEquals(struct ListNode * head1, struct ListNode * head2) {
    while (head1 != NULL || head2 != NULL) {
        //check if one is NULL
        if (head1 == NULL || head2 == NULL) {
            return false;
        }

        //compare values
        int v1 = head1->val;
        int v2 = head2->val;
        if (v1 != v2) {
            return false;
        }

        //move pointers
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}