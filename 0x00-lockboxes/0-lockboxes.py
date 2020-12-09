#!/usr/bin/python3
"""
Lockboxes interview question method
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """
    Method that determines if all the boxes can be opened.
    """
    if not boxes:
        return False

    n = len(boxes)
    keys = [0]

    for key in keys:
        for box in boxes[key]:
            if box < n and box not in keys:
                keys.append(box)

    if len(keys) != n:
        return False
    return True
