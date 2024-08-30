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
        if walls[left] > left_max:
            left_max = walls[left]