"""
Given a string s, return the longest palindromic substring in s.

Runtime: 463 ms
Faster than 93.37% of Python3 online submissions

Memory Usage: 13.9 MB
Less than 90.89% of Python3 online submissions
"""


def longestPalindrome(s: str) -> str:
    len_s = len(s)

    result = ""
    maxlen = 0
    for i in range(len_s):
        # single middle case
        start = i
        end = i
        length = -1  # first loop iteration will make length = 1
        while start >= 0 and end < len_s and s[start] == s[end]:
            # add to length of palindrome
            length += 2
            # move pointers
            start -= 1
            end += 1
        if length > maxlen:
            # adjust pointers back one to undo last loop iteration
            new_start = start + 1
            new_end = end - 1

            # save new longest
            maxlen = length
            result = s[new_start:new_end+1]

        # double middle case
        if i < len_s - 1 and s[i] == s[i + 1]:
            start = i
            end = i + 1
            length = 0  # first loop iteration will make length = 2
            while start >= 0 and end < len_s and s[start] == s[end]:
                # add to length of palindrome
                length += 2
                # move pointers
                start -= 1
                end += 1
            if length > maxlen:
                # adjust pointers back one to undo last loop iteration
                new_start = start + 1
                new_end = end - 1

                # save new longest
                maxlen = length
                result = s[new_start:new_end+1]

    return result


def test():
    TEST = [
        ("babad", "bab"),
        ("cbbd", "bb")
    ]
    for test in TEST:
        assert longestPalindrome(test[0]) == test[1]
