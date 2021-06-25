#!/usr/bin/python3
"""Making Change"""


def makeChange(coins, total):
    """Make Change to meet total from coins"""

    count = 0

    if total <= 0:
        return 0
    coins.sort(reverse=True)
    for coin in coins:
        while total >= coin:
            total -= coin
            count += 1
    if total != 0:
        return -1
    else:
        return count
