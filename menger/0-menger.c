#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * is_empty - Determinate if a gyven psition should be empty
 * @column: the column
 * @raw: the raw
 * Return: & if position is empty else 0
 */

int is_empty(int row, int column)
{
    while (row > 0 || column > 0)
    {
        if (row % 3 == 1 && column % 3 == 1)
            return 1;
        row /= 3;
        column /= 3;
    }
    return 0;
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: The level of the Menger Sponge to draw
 */
void menger(int level)
{
    int size, row, column;

    if (level < 1)
        return;

    size = pow(3, level);

    for (row = 0; row < size; row++)
    {
        for (column = 0; column < size; column++)
        {
            if (is_empty(row, column))
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}