#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array.
 *
 * @a: First element.
 * @b: Second element.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Maintains the max heap property.
 *
 * @array: The array to be sorted.
 * @size: Total size of the array.
 * @root: Root index of the current subtree.
 * @n: Size of the heap to consider (may shrink over time).
 */
void sift_down(int *array, size_t size, size_t root, size_t n)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size); /* Print after each swap */
		sift_down(array, size, largest, n);
	}
}

/**
 * heap_sort - Sorts array of integers in asce order using Heap sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	/* Build the max heap */
	for (int i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	/* Extract elements from the heap */
	for (int i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size); /* Print after each swap */
		sift_down(array, size, 0, i);
	}
}
