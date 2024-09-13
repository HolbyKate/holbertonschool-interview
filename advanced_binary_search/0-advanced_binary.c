#include <stdio.h>
#include <stddef.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @low: Starting index of the subarray
 * @high: Ending index of the subarray
 */
void print_array(int *array, size_t low, size_t high)
{
    size_t i;

    printf("Searching in array: ");
    for (i = low; i <= high; i++)
    {
        printf("%d", array[i]);
        if (i < high)
            printf(", ");
    }
    printf("\n");
}

/**
 * advanced_binary_recursive - Helper function to perform recursive binary search
 *
 * @array: Pointer to the first element of the array to search in
 * @low: Starting index of the subarray
 * @high: Ending index of the subarray
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
    if (high < low)
        return (-1);

    print_array(array, low, high);

    size_t mid = low + (high - low) / 2;

    if (array[mid] == value)
    {
        // Check if it is the first occurrence or continue to search in the left half
        if (mid == low || array[mid - 1] != value)
            return ((int)mid);
        return advanced_binary_recursive(array, low, mid - 1, value);
    }
    else if (array[mid] > value)
    {
        return advanced_binary_recursive(array, low, mid - 1, value);
    }
    else
    {
        return advanced_binary_recursive(array, mid + 1, high, value);
    }
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return advanced_binary_recursive(array, 0, size - 1, value);
}
