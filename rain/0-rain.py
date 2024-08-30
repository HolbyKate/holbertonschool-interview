#!/usr/bin/python3
"""
0-rain module
This module contains a function to calculate the amount of rainwater
retained between walls of different heights.
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.

    Args:
    walls (list of int): A list of non-negative integers representing the
    heights of walls with unit width 1, as if viewing the
    cross-section of a relief map.

    Returns:
    int: The total amount of rainwater retained.
    """
    if not walls:
        return 0

    left = 0
    right = len(walls) - 1
    left_max = right_max = water = 0

    while left < right:
        # Update the maximum height of the left wall
        if walls[left] > left_max:
            left_max = walls[left]

        # Update the maximum height of the right wall
        if walls[right] > right_max:
            right_max = walls[right]

        # If left wall is lower, calculate water for left side
        if left_max <= right_max:
            water += max(0, left_max - walls[left])
            left += 1
        else:
            water += max(0, right_max - walls[right])
            right -= 1

    return water
