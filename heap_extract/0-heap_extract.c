#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_size - Calculates the size of a heap
 * @root: Pointer to the root node of the heap
 *
 * Return: Size of the heap
 */
size_t heap_size(const heap_t *root)
{
	if (!root)
		return (0);
	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * get_last_node - Gets the last level-order node of the heap
 * @root: Pointer to the root node of the heap
 * @size: Size of the heap
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
	size_t binary_path = 1;

	while (binary_path <= size)
		binary_path <<= 1;
	binary_path >>= 2;

	while (binary_path > 0)
	{
		if (size & binary_path)
			root = root->right;
		else
			root = root->left;
		binary_path >>= 1;
	}
	return (root);
}

/**
 * heapify_down - Restores the Max Heap property
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;
	int temp;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *heap;
	int extracted_value;
	size_t heap_size_val;
	heap_t *last_node;

	if (!root || !*root)
		return (0);

	heap = *root;
	extracted_value = heap->n;
	heap_size_val = heap_size(heap);

	if (heap_size_val == 1)
	{
		free(heap);
		*root = NULL;
		return (extracted_value);
	}

	last_node = get_last_node(heap, heap_size_val);
	heap->n = last_node->n;

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);
	heapify_down(heap);

	return (extracted_value);
}
