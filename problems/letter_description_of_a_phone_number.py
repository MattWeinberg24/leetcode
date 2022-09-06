"""
Given a string containing digits from 2-9 inclusive,
return all possible letter combinations that the number could represent.
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons)
is given below. Note that 1 does not map to any letters.
"""


from typing import List


def letterCombinations(digits: str) -> List[str]:
    if not digits:
        return []

    m = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
        }

    results = ['']
    for digit in digits:
        # for each digit, find the corresponding 3 or 4 letters,
        # for each of those letters append it on to each of the results
        # of the previous digit
        results = [result+d for result in results for d in m[digit]]

    return results


def test():
    TEST = [
        ("23", ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]),
        ("", []),
        ("2", ["a", "b", "c"])
    ]
    for test in TEST:
        assert letterCombinations(test[0]) == test[1]
