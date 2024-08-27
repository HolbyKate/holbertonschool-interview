#!/usr/bin/python3
# Return: Integer indicating total amount of rainwater retained.

def rain(walls):
    # If list is empty, return 0
    if not walls:
        return 0

    left = 0
    right = len(walls) - 1
    left_max = right_max = water = 0

    while left < right:
        if walls[left] > left_max:
            left_max = walls[left]