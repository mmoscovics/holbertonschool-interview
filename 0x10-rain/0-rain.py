#!/usr/bin/python3
"""Rain"""


def rain(walls):
    """Calculate retained water"""
    if walls is None:
        return 0
    end = len(walls)
    water = 0

    if walls == 0 or end == 1:
        return 0
    for count in range(1, end - 1):
        left_wall = walls[count]
        for mark in range(count):
            left_wall = max(left_wall, walls[mark])
        right_wall = walls[count]
        for mark in range(count + 1, end):
            right_wall = max(right_wall, walls[mark])
        water += min(left_wall, right_wall) - walls[count]
    return water
