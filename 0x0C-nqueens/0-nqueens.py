#!/usr/bin/python3
"""N queens puzzle"""
import sys


def solve_nqueens(n, board, col):
    """solving function for n queens"""
    status = False
    if col == n:
        print_solutions(board)
        return True
    for row in range(n):
        if valid(n, board, row, col):
            board[row][col] = 1
            status = solve_nqueens(n, board, col + 1) or status
            board[row][col] = 0
    return status


def print_solutions(board):
    """print queen solutions"""
    solution = []
    for i in range(len(board)):
        pos = board[i].index(1)
        solution.append([i, pos])
    print(solution)


def valid(n, board, row, col):
    """checks valid position for queens"""
    for i in range(col):
        if board[row][i] == 1:
            return False
    x = row
    y = col
    while x >= 0 and y >= 0:
        if board[x][y] == 1:
            return False
        x -= 1
        y -= 1
    x = row
    y = col
    while x < n and y >= 0:
        if board[x][y] == 1:
            return False
        x += 1
        y -= 1
    return True


def main():
    """main function"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    if not sys.argv[1].isdigit():
        print("N must be a number")
        exit(1)
    n = int(sys.argv[1])
    if n < 4:
        print("N must be at least 4")
        exit(1)
    board = [[0 for x in range(n)]for y in range(n)]
    solve_nqueens(n, board, 0)


if __name__ == "__main__":
    main()
