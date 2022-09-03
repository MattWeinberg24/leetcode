/*
Implement the myAtoi(string s) function, 
which converts a string to a 32-bit signed integer 
(similar to C/C++'s atoi function).

Runtime: 0 ms (Faster than 100%) O(n)
Memory: 5.5 MB (Less than 87.02%)
*/

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Returns pointer to first non-whitespace character in s
 * 
 * @param s string to test
 * @return char* new string
 */
char * stringStart(char * s) {
    while (*s == ' ') {
        s++;
    }
    return s;
}


int myAtoi(char * s){

    //get string start
    s = stringStart(s);

    //check for + or -
    int sign = 1;
    if (*s == '-') {
        sign = -1;
        s++;
    }
    else if (*s == '+') {
        s++;
    }

    //create result
    int result = 0;
    while (*s >= 48 && *s <= 57) {
        
        //account for overflow
        /*
        Positive Case:
        Let r be the current result and d be the next digit.
        The following cannot be true:
        10r + d > INT_MAX
        Therefore:
        If r > INT_MAX / 10, there is overflow
        */
        if (result > __INT_MAX__ / 10 && sign == 1) return __INT_MAX__;

        /*
        If r == INT_MAX / 10, there is overflow if d > 7 (because integer division)
        */
        if (result == __INT_MAX__ / 10 && *s > 55) return __INT_MAX__;

        /*
        Negative Case:
        */
        int int_min = -1 * __INT_MAX__ - 1;
        if (result <  int_min / 10) return int_min;
        if (result == int_min / 10 && *s > 56) return int_min;

        int digit = *s - 48;
        if (sign == -1) {
            digit *= -1;
        }
        result = (result * 10) + digit;  // shift result and add new digit

        s++;  // advance string pointer
    }
    
    return result;
}

int main(int argc, char const *argv[]) {
    printf("%d\n",myAtoi("   422"));
    printf("%d\n",myAtoi("   -422dddd"));

    return 0;
}
