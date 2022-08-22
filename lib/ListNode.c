#include <stdlib.h>
#include <stdio.h>
#include "ListNode.h"

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

void printList(struct ListNode * head) {
    while (head != NULL) {
        printf("%d,", head->val);
        head = head->next;
    }
    printf("\n");
}

int assertListEquals(struct ListNode * head1, struct ListNode * head2, int size) {
    for (int i = 0; i < size; i++) {
        
    }
}