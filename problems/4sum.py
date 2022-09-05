"""
Given an array nums of n integers,
return an array of all the unique quadruplets
[nums[a], nums[b], nums[c], nums[d]] such that:

    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.
"""


from typing import List


def threeSum(nums: List[int], target: int) -> List[List[int]]:
    """
    Given an array nums of n integers,
    return an array of all the unique triplets
    [nums[a], nums[b], nums[c]] such that:

        0 <= a, b, c < n
        a, b, c are distinct.
        nums[a] + nums[b] + nums[c] == target

    You may return the answer in any order.

    Args:
        nums (List[int]): array of integers
        target (int): desired sum

    Returns:
        List[List[int]]: list of valid triplets
    """
    len_n = len(nums)
    result = []

    nums.sort()  # sort in ascending order

    for i in range(len_n - 2):  # test every first element in the triplet

        if i == 0 or (i > 0 and nums[i] != nums[i-1]):  # avoid duplicates
            t = target - nums[i]  # the other two numbers must add to this
            low = i + 1  # low pointer
            high = len_n - 1  # high pointer
            while low < high:
                sum = nums[low] + nums[high]
                if sum == t:
                    result.append([nums[i], nums[low], nums[high]])
                    # skip duplicates
                    while low < high and nums[low] == nums[low + 1]:
                        low += 1
                    low += 1  # add to pointer
                    # skip duplicates
                    while low < high and nums[high] == nums[high - 1]:
                        high -= 1
                    high -= 1
                elif sum < t:
                    low += 1  # need larger numbers
                else:
                    high -= 1  # need smaller numbers

    return result


def fourSum(nums: List[int], target: int) -> List[List[int]]:
    len_n = len(nums)

    nums.sort()

    result = []
    for i in range(len_n - 3):  # test every possible first element
        if (i == 0) or (i > 0 and nums[i] != nums[i - 1]):
            for r in threeSum(nums[i + 1:], target - nums[i]):
                result.append(r + [nums[i]])
    return result


def test():
    TEST = [
        (
            [1, 0, -1, 0, -2, 2],
            0,
            [[-1, 1, 2, -2], [0, 0, 2, -2], [0, 0, 1, -1]]
        ),
        (
            [2, 2, 2, 2, 2],
            8,
            [[2, 2, 2, 2]]
        )
    ]
    for test in TEST:
        assert fourSum(test[0], test[1]) == test[2]
