"""
Given an integer array nums, return all the triplets
[nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Runtime: 755 ms (Faster than 92.33%)
Memory: 18.1 MB (Less than 39.53%)
"""

from typing import List


def threeSum(nums: List[int]) -> List[List[int]]:
    len_n = len(nums)
    result = []

    nums.sort()  # sort in ascending order

    for i in range(len_n - 2):  # test every first element in the triplet

        # the smallest number in the triplet cannot be positive
        if nums[i] > 0:
            continue

        if i == 0 or (i > 0 and nums[i] != nums[i-1]):  # avoid duplicates
            target = 0 - nums[i]  # the other two numbers must add to this
            low = i + 1  # low pointer
            high = len_n - 1  # high pointer
            while low < high:
                sum = nums[low] + nums[high]
                if sum == target:
                    result.append([nums[i], nums[low], nums[high]])
                    # skip duplicates
                    while low < high and nums[low] == nums[low + 1]:
                        low += 1
                    low += 1  # add to pointer
                    # skip duplicates
                    while low < high and nums[high] == nums[high - 1]:
                        high -= 1
                    high -= 1
                elif sum < target:
                    low += 1  # need larger numbers
                else:
                    high -= 1  # need smaller numbers

    return result


def test():
    TEST = [
        ([-1, 0, 1, 2, -1, -4], [[-1, -1, 2], [-1, 0, 1]]),
        ([0, 1, 1], []),
        ([0, 0, 0], [[0, 0, 0]])
    ]
    for test in TEST:
        assert threeSum(test[0]) == test[1]
