struct ListNode {
    int val;
    struct ListNode * next;
};

struct ListNode * createList(int nums[], int size);
void printList(struct ListNode * head);
int assertListEquals(struct ListNode * head1, struct ListNode * head2, int size);