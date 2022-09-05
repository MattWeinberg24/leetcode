"""
Given an integer array nums of length n and an integer target,
find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
"""

from typing import List


def threeSumClosest(nums: List[int], target: int) -> int:
    len_n = len(nums)
    result = None
    result_delta = None

    nums.sort()

    for i in range(len_n - 2):  # try every first-element in result
        t = target - nums[i]
        low = i + 1  # first pointer
        high = len_n - 1  # second pointer
        while low < high:
            sum = nums[low] + nums[high]
            delta = sum - t
            if sum + nums[i] == target:
                return target
            if result_delta is None or abs(delta) < abs(result_delta):
                result_delta = delta
                result = nums[i] + nums[low] + nums[high]
            if delta < 0:
                while low < high and nums[low] == nums[low + 1]:
                    low += 1
                low += 1  # need larger numbers
            else:
                while low < high and nums[high] == nums[high - 1]:
                    high -= 1
                high -= 1  # need smaller numbers
    return result
