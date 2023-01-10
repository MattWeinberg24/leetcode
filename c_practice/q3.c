#include <stdio.h>
#include <stdlib.h>

/*
These exercises are intended to test your use of structs,
pointers,dynamic memory allocation and deallocation,
functions and function pointers (as well as basic program I/O)
to implement, use, and test basic data structures.

Implement and demonstrate memory-safe use of a singly linked list as follows: 
*/

/*
a)
Declare a struct that has two elements:
an integer and a pointer to the same struct type. 
*/
struct node {
    int val;
    struct node * next;
};

int main() {
    /*
    b)
    Use malloc to dynamically allocate four instances of that struct type
    and update their pointers to form a chain
    where each instance except for the last one points to the next one,
    and the last one points to nothing. 
    */
    struct node * head = malloc(sizeof(struct node));
    int i;
    struct node * cur = head;
    for (i = 0; i < 3; i++) {
        cur->next = malloc(sizeof(struct node));
        cur = cur->next;
    }

    /*
    c)
    Fill in the integer fields of those instances with four different values
    and then print out the instances integer values in order,
    from the beginning to the end of the list. 
    */
    cur = head;
    for (i = 0; i < 4; i++) {
        cur->val = i;
        cur = cur->next;
    }
    cur = head;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");

    /*
    d)
    Remove the second instance from the list,
    keeping the list intact (with the first element in the list
    now pointing to what used to be the third element in the list)
    and using free to dynamically deallocate the memory
    for the instance that you removed from the list,
    and then again print out the instances integer values in order,
    from the beginning to the end of the list,
    to confirm that the correct element was removed from the list. 
    */
    struct node * n2 = head->next;
    struct node * n3 = n2->next;
    head->next = n3;
    free(n2);
    cur = head;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");

    return 0;
}