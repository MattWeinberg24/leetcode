from typing import List


def getTotalEfficiency(skill: List[int]) -> int:
    """
    You are given n number people with different skill levels.
    You must pair them up so that each pair has the same sum
    skill levels. Calculate the total "efficiency" of every pair
    combined, which is the product of the two members' skills.
    If not possible, return -1. Otherwise return the total efficiency.

    Args:
        skill (List[int]): List of skill levels

    Returns:
        int: total efficiency if successful, -1 if not
    """
    result = 0
    target = None

    # sort list
    skill.sort()

    # pointers
    p1 = 0
    p2 = len(skill) - 1

    while p1 < p2:
        s1 = skill[p1]
        s2 = skill[p2]
        if target is None:
            # first pair (determine target)
            target = s1 + s2
            result += s1 * s2
            p1 += 1
            p2 -= 1
        elif s1 + s2 == target:
            # second pair onwards much sum to target
            result += s1 * s2
            p1 += 1
            p2 -= 1
        else:
            # otherwise fail
            return -1

    return result
