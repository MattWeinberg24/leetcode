def checkIPValidity(addressIP: str) -> str:
    """
    Given a string, determine whether it is a valid IP address.
    Valid IP addresses are 4 numbers between 0 and 255 separated
    by a period (example: "1.42.255.0")

    Args:
        addressIP (str): IP address

    Returns:
        str: "VALID" or "INVALID"
    """

    # Write your code here
    nums = addressIP.split(".")

    # must be 4 numbers
    if len(nums) != 4:
        return "INVALID"

    for num in nums:
        try:
            num = int(num)
            if num < 0 or num > 255:
                # if not in range
                return "INVALID"
        except ValueError as e:
            # caught if invalid character
            return "INVALID"

    return "VALID"
