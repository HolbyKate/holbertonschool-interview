#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Maximum number of digits identification
 * @array: Array of integers
 * @size: Size of the array
 *
 * Return: The maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

/**
 * counting_sort - sorting by counting on array according to specific number
 * @array: The array
 * @size: Sizein the array
 * @exp: The specific number
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	print_array(array, size);
}

/**
 * radix_sort - Sort an array  in ascending order
 * @array: The array
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort(array, size, exp);
}
