#!/usr/bin/python3
"""Function that return the perimeter of the island"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island in a 2D grid.

    Args:
        grid (List[List[int]]): A rectangular grid where:
            - 0 represents water
            - 1 represents land
            - The width and height don't exceed 100

    Returns:
        int: The perimeter of the island

    Example:
        >>> grid = [
        ...     [0, 0, 0, 0, 0, 0],
        ...     [0, 1, 0, 0, 0, 0],
        ...     [0, 1, 0, 0, 0, 0],
        ...     [0, 1, 1, 1, 0, 0],
        ...     [0, 0, 0, 0, 0, 0]
        ... ]
        >>> island_perimeter(grid)
        12
    """

    if not grid:
        return 0

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    # define parameter
    for i in range(rows):
        for j in range(cols):
            if grid[i] == 1:
                perimeter += 4

                # Check cell on top
                if i > 0 and grid[i-1][j] == 1:
                    perimeter -= 2

                # Check cell to the left
                if j > 0 and grid[i][j-1] == 1:
                    perimeter -= 2

    return perimeter
