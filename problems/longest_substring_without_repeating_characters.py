def lengthOfLongestSubstring(s: str) -> int:
    result = 0  # keep track of longest
    start = 0  # current starting index of result
    d = {}  # used characters

    # go through each character...
    for (i, c) in enumerate(s):
        if c in d and start <= d[c]:
            # if duplicate found ahead of start, update start
            start = d[c] + 1
        else:
            # otherwise update result if necessary
            new_result = i - start + 1
            result = max(result, new_result)

        d[c] = i  # add to used characters

    return result


TEST = [
    ("abcabcbb", 3),
    ("bbbbb", 1),
    ("pwwkew", 3)
]


def test():
    for test in TEST:
        assert lengthOfLongestSubstring(test[0]) == test[1]
