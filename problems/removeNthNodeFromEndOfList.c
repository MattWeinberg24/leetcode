#include <stdlib.h>
#include <stdio.h>
#include "../lib/ListNode.h"

struct ListNode * removeNthFromEnd(struct ListNode * head, int n) {
    
    // first pass: get size of list
    int size = listSize(head);
    // if removing first node
    if (n == size) {
        return head->next;
    }
    
    // second pass: remove node
    struct ListNode * node = head;
    int node_before = size - n - 1;  // go to node before one to remove
    for (int i = 0; i < node_before; i++) {
        node = node->next;
    }
    // if removing last node
    if (n == 1) {
        node->next = NULL;
    }
    // removing any other node
    else {
        node->next = node->next->next;
    }

    return head;
}

int main(int argc, char const *argv[]) {
    int n[] = {1,2,3,4,5};
    struct ListNode * l = createList(n, 5);
    printList(l);
    printf("%d\n", listSize(l));

    removeNthFromEnd(l, 2);
    printList(l);
    printf("%d\n", listSize(l));

    free(l);
    return 0;
}
