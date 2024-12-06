#!/usr/bin/python3
"""
Function that returns a list of lists of integers like a Pascal's triangle
"""


def pascal_triangle(n):
    # Returns empty if negative or null
    if n <= 0:
        return []

    triangle = [1]

    # Create each line
    for i in range(1, n):
        prev_row = triangle[-1]
        # Start with new line
        new_row = [1]
