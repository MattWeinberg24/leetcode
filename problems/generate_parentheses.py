"""
Given n pairs of parentheses,
write a function to generate all combinations of
well-formed parentheses.
"""


from typing import List


def generateParentheses(n: int) -> List[str]:
    result = []

    generate(result, "", n, 0)

    return result


def generate(res: List[str], s: str, open_left: int, closed_left: int):
    """
    Based on how many open and closed parentheses are "left",
    either add the current string if there are none,
    or recursively build the string if there are any left

    Args:
        res (List[str]): running list of valid parentheses
        s (str): current string being built
        open_left (int): how many opening parentheses are remaining
        closed_left (int): how many closing parentheses are remaining
    """
    # base case
    if open_left == 0 and closed_left == 0:
        res.append(s)
        return

    # recursive case
    if open_left > 0:
        generate(res, s + "(", open_left - 1, closed_left + 1)

    if closed_left > 0:
        generate(res, s + ")", open_left, closed_left - 1)


def test():
    TEST = [
        (1, ["()"]),
        (2, ["(())", "()()"]),
        (3, ["((()))", "(()())", "(())()", "()(())", "()()()"])
    ]
    for test in TEST:
        assert generateParentheses(test[0]) == test[1]
