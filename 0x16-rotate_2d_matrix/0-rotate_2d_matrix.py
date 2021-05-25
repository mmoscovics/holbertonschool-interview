#!/usr/bin/python3
"""Rotate a 2d matrix"""


def rotate_2d_matrix(matrix):
    """Rotates an n x n 2d matrix 90 degrees clockwise"""
    n = len(matrix)
    temp = [[0 for col in range(n)] for row in range(n)]
    for row in range(n):
        for col in range(n):
            temp[col][n - row - 1] = matrix[row][col]
    for row in range(n):
        for col in range(n):
            matrix[row][col] = temp[row][col]
