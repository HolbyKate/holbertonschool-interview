#!/usr/bin/python3
"""Function that return the perimeter of the island"""

def island_perimeter(grid):
    """
        Calculate the perimeter of the island described in grid.

        Args:
            grid (List[List[int]]): A 2D grid where:
                - 0 represents water
                - 1 represents land

        Returns:
            int: The perimeter of the island
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
