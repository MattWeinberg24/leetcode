def distance(c1: str, c2: str) -> int:
    """Get the lexographical distance between two characters

    Args:
        c1 (str): character 1
        c2 (str): character 2

    Returns:
        int: minimum lexographical distance
    """
    d1 = (ord(c1) - ord(c2)) % 26
    d2 = 26 - d1
    return min(d1, d2)


def totalDistance(s1: str, s2: str) -> int:
    """Get the total lexographical distance between characters in two strings

    Args:
        s1 (str): string 1
        s2 (str): string 2 (same length)

    Returns:
        int: total lexographical distance
    """
    result = 0
    len_s = len(s1)
    # calculate distance for each character and sum it up
    for i in range(len_s):
        result += distance(s1[i], s2[i])
    return result


def getSmallestString(s: str, k: int) -> str:
    """find the lexographically-first string
    with a maximum distance k from s

    Args:
        s (str): original string
        k (int): maximum allowed distance

    Returns:
        str: lexographically-first string with max distance k
    """
    len_s = len(s)

    result = ['a'] * len_s
    i = len_s - 1
    success = False
    d = totalDistance(s, ''.join(result))

    while (i >= 0):
        old_distance = distance(s[i], result[i])
        while (result[i] != s[i]):
            if d <= k:
                success = True
                break

            result[i] = chr(ord(result[i]) + 1)

            new_distance = distance(s[i], result[i])
            if old_distance > new_distance:
                d -= 1
            else:
                d += 1
            old_distance = new_distance
        if success:
            break
        i -= 1

    return ''.join(result)
