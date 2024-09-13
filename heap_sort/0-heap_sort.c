#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swap two elements in an array
 *
 * @array: The array to be sorted
 * @i: The index of the first element
 * @j: The index of the second element
 */
void swap(int *array, size_t i, size_t j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * sift_down - Sift down the element at index i in a max heap
 *
 * @array: The array representing the heap
 * @size: Total size of the array
 * @n: Size of the heap portion of the array
 * @i: The index of the element to sift down
 */
void sift_down(int *array, size_t size, size_t n, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(array, i, largest);
		print_array(array, size);

		sift_down(array, size, n, largest);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order using Heap sort
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	for (size_t i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, size, i);

	for (size_t i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);
		print_array(array, size);

		sift_down(array, size, i, 0);
	}
}
