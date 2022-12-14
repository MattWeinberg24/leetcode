#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode * next;
};

struct ListNode * createList(int nums[], int size);
int listSize(struct ListNode * head);

void printList(struct ListNode * head);
bool assertListEquals(struct ListNode * head1, struct ListNode * head2);
