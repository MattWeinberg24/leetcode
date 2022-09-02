#include <stdio.h>
#include "Array.h"

/**
 * @brief Prints a simple view of an integer array
 * 
 * @param arr Pointer to start of array
 * @param size Size of array (or number of values to print)
 */
void printArray(int * arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d,", arr[i]);
    }
    printf("]\n");
}
