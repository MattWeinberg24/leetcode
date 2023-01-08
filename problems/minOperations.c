/**
 * @brief You are given an integer array nums (0-indexed). 
 * In one operation, you can choose an element of the array and increment it by 1.
 * For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3].
 * Return the minimum number of operations needed to make nums strictly increasing.
 * 
 * @param nums number array
 * @param numsSize size of number array
 * @return int minimum operations
 */
int minOperations(int* nums, int numsSize){
    int result = 0;
    int prev = nums[0];
    for (int i = 1; i < numsSize; i++) {
        int n = nums[i]; //save nums[i] to prevent repeated array access
        int toAdd = prev - n + 1; //nums[i] - nums[i-1] + 1
        if (toAdd > 0) {
            result += toAdd;
            prev = n + toAdd;
        }
        else {
            prev = n;
        }
    }
    return result;