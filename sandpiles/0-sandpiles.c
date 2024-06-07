#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - prints a grid
 * @grid: grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * add_grids - sums two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 */
void add_grids(int grid1[3][3], int grid2[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			grid1[i][j] += grid2[i][j];
}

/**
 * is_stable - checks if a sandpile is stable
 * @grid: sandpile to check
 *
 * Return: 1 if stable, 0 otherwise
 */
int is_stable(int grid[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * topple - topples an unstable sandpile
 * @grid: sandpile to topple
 */
void topple(int grid[3][3])
{
	int i, j;
	int temp_grid[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if (grid[i][j] > 3)
			{
				temp_grid[i][j] -= 4;
				if (i - 1 >= 0)
					temp_grid[i - 1][j]++;
				if (i + 1 < 3)
					temp_grid[i + 1][j]++;
				if (j - 1 >= 0)
					temp_grid[i][j - 1]++;
				if (j + 1 < 3)
					temp_grid[i][j + 1]++;
			}
		}
	}

	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			grid[i][j] += temp_grid[i][j];
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_grids(grid1, grid2);

	while (!is_stable(grid1))
	{
		puts("=");
		print_grid(grid1);
		topple(grid1);
	}
}
