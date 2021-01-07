#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):
    """
    Method that calculates the fewest number of operations needed
    to result in exactly n characters, when given n.
    """

    count = 0
    chars = 1

    if n < 1:
        return 0
    total = chars
    while total < n:
        if n % total == 0:
            chars = total
            count += 1
        total += chars
        count += 1
    return count
