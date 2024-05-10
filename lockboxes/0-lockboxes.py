#!/usr/bin/python3
"""Method that determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    unlock = boxes[0]
    """First loop for the key"""
    for key in range(1, len(boxes)):
        locker = False
        for box in range(len(boxes)):
            """check if key are in the box"""
            if key in boxes[box] and box != key:
                locker = True
                break
        """check if no box can be open with the key"""
        if not locker:
            return False
    return True
