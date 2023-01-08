#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
a)
Define a structure called part containing 
an int variable partNumber, and char array partName 
whose values may be as long as 25 characters. 
*/
struct part {
    int partNumber;
    char partName[25];
};

/*
b)
Define Part to be a synonym for the type struct part. 
*/
#define Part struct part

int main() {
    /*
    c)
    Use Part to declare variable a to be of type struct part,
    array b[10] to be of type struct part,
    and variable ptr to be of type pointer to struct part. 
    */
    Part a;
    Part b[10];
    Part * ptr;

    /*
    d)
    Read a part number and a part name from the keyboard 
    into the individual members of variable a. 
    */
    printf("Enter part number for 'a':\n");
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
    a.partNumber = (int) strtol(buffer, NULL, 10);

    printf("Enter part name for 'a':\n");
    fgets(a.partName, sizeof(a.partName), stdin);
    // remove trailing newline
    size_t newlineIndex = strlen(a.partName) - 1;
    if (a.partName[newlineIndex] == '\n') {
        a.partName[newlineIndex] = '\0';
    }

    printf("\nA:\nName: %s\nNumber: %d\n", a.partName, a.partNumber);

    /*
    e)
    Assign the member values of variable a to element 3 of array b. 
    */
    b[3].partNumber = a.partNumber;
    strncpy(b[3].partName, a.partName, sizeof(b[3].partName));
    printf("\nb[3]:\nName: %s\nNumber: %d\n", b[3].partName, b[3].partNumber);

    /*
    f)
    Assign the address of array b to the pointer variable ptr
    */
    ptr = b;

    /*
    g)
    Print the members values of element 3 of array b to the display
    using the variable ptr and the structure pointer operator
    to refer to the members. 
    */
    ptr += 3;
    printf("\nb[3] (using ptr):\nName: %s\nNumber: %d\n", ptr->partName, ptr->partNumber);

    return 0;
}
