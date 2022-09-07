#include <stdio.h>
#include "Array.h"

/**
 * @brief Merge sorted integer subarrays into single sorted array
 * (used by merge sort)
 * 
 * @param arr pointer to start of array
 * @param low low index
 * @param mid mid index (last index of first subarray)
 * @param high high index
 */
void merge(int * arr, int low, int mid, int high) {
    // left subarray
    int nLeft = mid - low + 1;
    // printf("nLeft: %d\n", nLeft);
    int left[nLeft];
    for (int i = 0; i < nLeft; i++) {
        left[i] = arr[low + i];
    }

    // right subarray
    int nRight = high - mid;
    // printf("nRight: %d\n", nRight);
    int right[nRight];
    for (int i = 0; i < nRight; i++) {
        right[i] = arr[mid + 1 + i];
    }

    //merge
    int i = low;  // merged array index
    int l = 0;  // left subarray index
    int r = 0;  // right subarray index
    while (l < nLeft || r < nRight) {
        // printf("i: %d\n", i);

        // both subarrays not complete
        if (l < nLeft && r < nRight) {
            //add smaller value and advance respective index
            if (left[l] <= right[r]) {
                arr[i] = left[l];
                l++;
            }
            else {
                arr[i] = right[r];
                r++;
            }
        }

        // left subarray not complete
        else if (l < nLeft) {
            arr[i] = left[l];
            l++;
        }

        // right subarray not complete
        else {
            arr[i] = right[r];
            r++;
        }

        i++;
    }
}

/**
 * @brief Sorts an integer array efficiently
 * 
 * @param arr pointer to start of array
 * @param low low index to sort (usually 0 to start)
 * @param high high index to sort (usually length - 1 to start)
 */
void mergeSort(int * arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

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
