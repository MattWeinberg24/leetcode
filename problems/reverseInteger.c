/*
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the 
signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers
(signed or unsigned).

Runtime: 0 ms (Faster than 100%) O(log(n))
Space: 5.4 MB (Less than 88.57%)
*/

#include <stdlib.h>
#include <stdio.h>

int reverse(int x) {

    int result = 0;
    while (x != 0) {
        int digit = x % 10;  // get least significant digit

        //account for overflow
        /*
        Positive Case:
        Let r be the current result and d be the next digit.
        The following cannot be true:
        10r + d > INT_MAX
        Therefore:
        If r > INT_MAX / 10, there is overflow
        */
        if (result > __INT_MAX__ / 10) return 0;

        /*
        If r == INT_MAX / 10, there is overflow if d > 7 (because integer division)
        */
        if (result == __INT_MAX__ / 10 && digit > 7) return 0;

        /*
        Negative Case:
        Same except signs are reversed and d cannot be less than -8 instead of 7
        */
        int int_min = -1 * __INT_MAX__ - 1;
        if (result <  int_min / 10) return 0;
        if (result == int_min / 10 && digit < -8) return 0;

        result = (result * 10) + digit;  // shift result and add new digit
        x /= 10;  // advance digit pointer
    }
    
    return result;
}

int main(int argc, char const *argv[]) {
    int numTests = 3;
    int test[] = {
        123, 321, // test 1
        -123, -321,  // test 2
        120, 21  // test 3
    };
    
    for (int i = 0; i < numTests; i++) {
        if (reverse(test[i * 2]) == test[i * 2 + 1]) {
            printf("Test %d: Success\n", i + 1);
        }
        else {
            printf("Test %d: Failure\n", i + 1);
        }
    }

    return 0;
}
