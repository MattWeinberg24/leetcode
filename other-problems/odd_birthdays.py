from typing import List


def numberOfDays(days: List[int]) -> int:
    """
    Given a list of integers ("birthdays"),
    identify how many birthdays occur an odd
    number of times.

    Args:
        days (List[int]): list of birthdays

    Returns:
        int: how many birthdays occur an odd number of times
    """
    result = 0

    # see how many times each birthday occurs
    bday_dict = {}
    for day in days:
        if day in bday_dict:
            bday_dict[day] += 1
        else:
            bday_dict[day] = 1

    # determine which days have an odd number
    for day in bday_dict:
        if (bday_dict[day] + 1) % 2 == 0:  # n is odd if n + 1 is even
            result += 1

    return result
