#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: The first integer
 * @b: The second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Restores the heap property in a subtree
 * @array: The array representing the heap
 * @start: The index of the root of the subtree
 * @end: The index of the last element of the heap
 * @size: The total size of the array (used for printing)
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child;
	size_t swap_idx;

	while ((child = 2 * root + 1) <= end)
	{
		swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;
		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;
		if (swap_idx == root)
			return;

		swap(&array[root], &array[swap_idx]);
		print_array(array, size);
		root = swap_idx;
	}
}

/**
 * heap_sort - Sorts an array of integers in
 * ascending order using Heap sort
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	size_t start, end;

	if (size < 2)
		return;

	for (start = (size - 2) / 2; (int)start >= 0; start--)
		sift_down(array, start, size - 1, size);

	for (end = size - 1; end > 0; end--)
	{
		swap(&array[0], &array[end]);
		print_array(array, size);
		sift_down(array, 0, end - 1, size);
	}
}
