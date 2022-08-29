"""
You are given an integer array height of length n.
There are n vertical lines drawn such that the
two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container,
such that the container contains the most water.

Return the maximum amount of water a container can store.

Time: 743 ms (Faster than 96.91%) O(n)
Space: 27.5 MB (Less than 49.35%)
"""


from typing import List


def max_area(height: List[int]) -> int:
    current_max = 0  # keeps track of maximum
    list_len = len(height)

    # start with pointers to first and last height
    left = 0
    right = list_len - 1

    # greedily shrink the shorter side since to find a new maximum area
    # with a smaller width you need a larger height
    while left < right:
        # calculate current area
        area = (right - left) * min(height[left], height[right])

        # determine if new current_max
        if area > current_max:
            current_max = area

        # move pointer on smaller height
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1

    return current_max


def test():
    TEST = [
        ([1, 8, 6, 2, 5, 4, 8, 3, 7], 49),
        ([1, 1], 1)
    ]

    for test in TEST:
        assert max_area(test[0]) == test[1]
