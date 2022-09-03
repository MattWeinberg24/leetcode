#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../lib/ListNode.h"
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode r;
    r.val = 0;
    r.next = NULL;
    
    struct ListNode * rn = &r;
    
    int carry = 0;
    struct ListNode * n1 = l1;
    struct ListNode * n2 = l2;
    while (n1 != NULL || n2 != NULL || carry != 0) {
        int v1 = 0;
        int v2 = 0;
        
        if (n1 != NULL) {
            v1 = n1->val;
            n1 = n1->next;
        }
        if (n2 != NULL) {
            v2 = n2->val;
            n2 = n2->next;
        }
        
        int sum = (v1 + v2 + carry) % 10;
        carry = (v1 + v2 + carry) / 10;
        
        rn->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        rn->next->val = sum;
        rn->next->next = NULL;
        rn = rn->next;
        
    }
    return r.next;
}

int main(int argc, char const *argv[]) {
    //input
    int expectedNums[] = {7,0,8};
    int nums1[] = {2,4,3};
    int nums2[] = {5,6,4};
    struct ListNode * expected = createList(expectedNums,3);
    struct ListNode * l1 = createList(nums1, 3);
    struct ListNode * l2 = createList(nums2, 3);

    //print list info
    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);
    printf("Expected Output: ");
    printList(expected);

    // calculate
    struct ListNode * r = addTwoNumbers(l1,l2);
    printf("Result: ");
    printList(r);

    // assert success
    bool success = assertListEquals(expected,r);
    if (success) {
        printf("Success!\n");
    }
    else {
        printf("Failure.\n");
    }

    // free pointers
    free(l1);
    free(l2);
    free(expected);
    free(r);
}
