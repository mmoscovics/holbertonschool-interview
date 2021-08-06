#!/usr/bin/python3
"""
Pascals triangle representation
"""


def pascal_triangle(n):
    """Returns list of ints as representation of pascals triangle"""

    l_list = []

    if n <= 0:
        return []
    for i in range(1, n + 1):
        n_list = []
        num = 1
        for j in range(1, i + 1):
            n_list.append(num)
            num = int(num * (i - j) // j)
        l_list.append(n_list)
    return l_list
