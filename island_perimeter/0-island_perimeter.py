#!/usr/bin/python3
"""Function that return the perimeter of the island"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island in a 2D grid.

    Detailed description:
        - The island is represented by 1's (land) surrounded by 0's (water)
        - Each cell is a square with side length of 1
        - Cells are connected horizontally/vertically (not diagonally)
        - The grid is completely surrounded by water
        - There is only one island (or nothing)
        - There are no "lakes" (water inside that isn't connected to the water surrounding the island)

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
        if grid[i] == 1:
            perimeter += 4

    for j in range(cols):
        if grid[j] == 1:
            perimeter += 4
            # Check cell on top
            if i > 0 and grid[i-1][j] == 1:
                perimeter -= 2

            # Check cell to the left
            if j > 0 and grid[i][j-1] == 1:
                perimeter -= 2
    return perimeter
