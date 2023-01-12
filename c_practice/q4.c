#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
Write code to demonstrate various techniques for
function invocation and use, as follows: 
*/

struct node {
    int val;
    struct node * next;
};

/*
a)
Declare and define a function that takes an unsigned integer as its only input
and returns a pointer to a dynamically allocated linked list
(using the techniques from the exercises above)
of all of the prime factors of that unsigned integer
(for example: if the function was given 15 then
the list should have two elements,a five and a three;
if the function was given 12 then
the list should have three elements, two twos and a three;
if the function was given 0 or 1 then the list should be empty). 
*/
struct node * primeList(unsigned int n) {
    if (n < 2) {
        return NULL;
    }

    //prime factorization algorithm adapted from https://www.geeksforgeeks.org/prime-factor/
    struct node * head = malloc(sizeof(struct node));
    struct node * prev = NULL;
    struct node * cur = head;
    while (n % 2 == 0) {
        cur->val = 2;
        cur->next = malloc(sizeof(struct node));
        prev = cur;
        cur = cur->next;
        n = n / 2;
    }
    int i;
    for (i = 3; i < sqrt(n); i += 2) {
        while (n % i == 0) {
            cur->val = i;
            cur->next = malloc(sizeof(struct node));
            prev = cur;
            cur = cur->next;
            n = n / i;
        }
    }
    if (n > 2) {
        cur->val = n;
        cur->next = malloc(sizeof(struct node));
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    free(cur);
    return head;
}

/*
b)
Declare and define a function that
takes a pointer to a dynamically allocated linked list
(of the same type that the function from the previous exercise produces),
prints out the integers in that list to the standard output stream,
and then iterates through the list using free
to dynamically deallocate the memory for each instance in the list. 
*/
void printAndFree(struct node * head) {
    while (head != NULL) {
        printf("%d,", head->val);
        struct node * prev = head;
        head = head->next;
        free(prev);
    }
    printf("\n");
}

/*
c)
Write a program that takes a single command line argument,
converts it into its equivalent unsigned integer representation
(for example the string "11" should become the unsigned integer 11,
the string "0" should become the unsigned integer 0, etc.),
passes it into a call to the first function you implemented above,
and then passes the pointer that was returned by that function
into a call to the second function you implemented above -
compile and run your program with different input values
to confirm it can handle various cases correctly without crashing
(e.g., due to problems with pointer initialization, memory management, etc.)
and that it returns the correct values in each case. 
*/
int main(int argc, char * argv[]) {
    // struct node * l = primeList(15);
    // printAndFree(l);
    if (argc != 2) {
        return 1;
    }
    
    unsigned int n = strtoul(argv[1],NULL,10);
    struct node * l = primeList(n);
    printAndFree(l);

    return 0;
}