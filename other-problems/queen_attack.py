def checkAttackTheOpponent(cord_x1: int, cord_y1: int,
                           cord_x2: int, cord_y2: int) -> str:
    """
    In chess, a queen can attack opponents on the same
    row, column, or diagonal. Given the queen and opponent's
    position, can the queen attack?

    Args:
        cord_x1 (int): queen x
        cord_y1 (int): queen y
        cord_x2 (int): opponent x
        cord_y2 (int): opponent y

    Returns:
        str: "Yes" if can, "No" if can't
    """

    # check same x
    if cord_x1 == cord_x2:
        return "Yes"

    # check same y
    if cord_y1 == cord_y2:
        return "Yes"

    # check same diagonal
    delta_x = abs(cord_x1 - cord_x2)
    delta_y = abs(cord_y1 - cord_y2)
    if delta_x == delta_y:
        return "Yes"

    return "No"
