"""
The string "PAYPALISHIRING" is written in a
zigzag pattern on a given number of rows like this:

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and
make this conversion given a number of rows.

SOLUTION:
Where n = len(s), Time is O(n) and Space is O(n)
Runtime: 83 ms (Faster than 68.71%)
Memory: 13.9 MB (Less than 76.10%)
"""


def convert(s: str, numRows: int) -> str:

    # if 1 row, the result is just the string itself
    if numRows == 1:
        return s

    len_s = len(s)
    result = ""

    # note: Time is O(n) because each character indexed only once
    for r in range(numRows):
        row_result = ""

        # To identify the pattern, draw out a string of "0123456" etc.
        # and identify the "step-distance" for each row, and how it
        # relates to numRows and the current row index.
        # The result is that each row will alternate between the following
        # delta_1 and delta_2, unless one of them is zero, as then the non-zero
        # delta will always be used.
        using_delta_1 = True  # track which delta to use next
        delta_1 = 2 * (numRows - 1) - (2 * r)
        delta_2 = 2 * (numRows - 1) - delta_1
        # check for zero
        if delta_1 == 0:
            delta_1 = delta_2
        elif delta_2 == 0:
            delta_2 = delta_1

        i = r  # first character of row corresponds to row number
        while i < len_s:  # until index is out of bounds...
            row_result += s[i]  # add character to row result

            # shift index and switch delta for next iteration
            if using_delta_1:
                i += delta_1
                using_delta_1 = False
            else:
                i += delta_2
                using_delta_1 = True

        result += row_result

    return result


def test():
    TEST = [
        ("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"),
        ("PAYPALISHIRING", 4, "PINALSIGYAHRPI"),
        ("A", 1, "A")
    ]

    for test in TEST:
        assert convert(test[0], test[1]) == test[2]
