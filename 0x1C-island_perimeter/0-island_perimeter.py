#!/usr/bin/python3
"""Island Perimeter function to determine island perimeter"""


def island_perimeter(grid):
    """Function to return perimeter of a described island"""
    total = 0
    rows = len(grid)
    cols = len(grid)

    for row in range(rows):
        for col in range(cols):
            pos = grid[row][col]
            if pos == 1:
                total += 4
                if row != 0 and grid[row-1][col] == 1:
                    total -= 1
                if col != 0 and grid[row][col-1] == 1:
                    total -= 1
                if row + 1 != rows and grid[row + 1][col] == 1:
                    total -= 1
                if col + 1 != cols and grid[row][col + 1] == 1:
                    total -= 1
    return total
