#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/*Declaration of prototypes*/
int is_unstable(int grid[3][3]);
void print_grid(int grid[3][3]);
void toppling(int grid[3][3]);

/**
* sandpiles_sum - Computes sum of two sandpiles
* @grid1: Left 3x3 grid
* @grid2: Right 3x3 grid
*
*/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    /*Compute the sum of the 2 sandpiles*/

    for (i = 0; i <3; i++)
    {
        for (j = 0; j <3; j++)
        {
            grid1[i][j] +=grid2[i][j];
        }
    }
    /*Loop until sandpiles is stable*/
    while (is_unstable(grid1))
    {
        print_grid(grid1);
        toppling(grid1);
    }
}

/**
* is_unstable - Checks if a sandpile is unstable
* @grid: 3x3 grid
*
* Return: 1 if the sandpile is unstable, 0 otherwise
*/

int is_unstable(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            /*if cell has more than 3 grains, this is unstable*/
            if (grid[i][j] > 3)
            {
                return 1;
            }
        }
    }

    return 0;
}

/**
* toppling - Performs a toppling round on a sandpile
* @grid: 3x3 grid
*
* Description: This function performs a toppling round on the sandpile.
* It topples all unstable cells and distributes the grains to the neighboring
* cells.
*/

void toppling(int grid[3][3])
{
    int i, j;
    int next_grid[3][3];

for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            next_grid[i][j] = grid[i][j];
        }
    }

    // Perform the toppling
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                next_grid[i][j] -= 4;

                if (i > 0)
                    next_grid[i - 1][j]++;
                if (i < 2)
                    next_grid[i + 1][j]++;
                if (j > 0)
                    next_grid[i][j - 1]++;
                if (j < 2)
                    next_grid[i][j + 1]++;
            }
        }
    }

    // Copy the next grid back to the original grid
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid[i][j] = next_grid[i][j];
        }
    }
}
/**
* print_grid - Print 3x3 grid
* @grid: 3x3 grid
*
*/

void print_grid(int grid[3][3])
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
