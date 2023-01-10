#include <stdio.h>
#include <string.h>

double number1 = 7.3, number2;
char s1[100] = "Hello", s2[100];

int main() {
    /*
    a)
    Declare the variable dPtr to be a pointer to a variable of type double. 
    */
    double * dPtr;

    /*
    b)
    Assign the address of variable number1 to pointer variable dPtr. 
    */
    dPtr = &number1;

    /*
    c)
    Print the value of the variable pointed to by dPtr to the display. 
    */
    printf("dPtr value: %f\n", *dPtr);

    /*
    d)
    Assign the value of the variable pointed to by dPtr to variable number2. 
    */
    *dPtr = number2;

    /*
    e)
    Print the value of number2 to the display. 
    */
    printf("number2 value: %f\n", number2);

    /*
    f)
    Print the address of number1 to the display.
    */
    printf("number1 addr: %p\n", &number1);

    /*
    g)
    Print the address stored in dPtr to the display.
    */
    printf("dPtr addr: %p\n", dPtr);

    /*
    h)
    Is the value printed equal to the address of number1?
    */
    if (dPtr == &number1) {
        printf("dPtr addr equal to number1 addr\n");
    }
    else {
        printf("dPtr addr NOT equal to number1 addr\n");
    }
    

    /*
    i)
    Copy the string stored in character array s1 into character array s2. 
    */
    strncpy(s2, s1, sizeof(s2));

    /*
    j)
    Compare the string stored in character array s1
    with the string in character array s2,
    and print the result to the display. 
    */
    if (strcmp(s1, s2) == 0) {
        printf("string s1 equal to string s2\n");
    }
    else {
        printf("string s1 NOT equal to string s2\n");
    }

    /*
    k)
    Append the string in character array s2 to the string in character array s1.
    Will this cause a run-time error? 
    */
    strcat(s1, s2);
    /*
    answer: There won't be a guaranteed runtime error,
    but if the combined size of s1 and s2 is larger than s1's buffer size,
    a buffer overflow will occur which may cause an error
    */

    /*
    l)
    Determine the length of the string stored in character array s1, and print the result to the display. 
    */
    printf("s1 length: %d\n", strlen(s1));
    
    return 0;
}