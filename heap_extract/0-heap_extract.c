#include "binary_trees.h"

/**
 * heap_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t heap_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * heapify_down - heapify from top to bottom
 * @root: pointer to the root of the heap
 */
void heapify_down(heap_t *root)
{
	heap_t *max = NULL;
	int temp;

	while (1)
	{
		if (!root->left)
			break;
		if (!root->right)
			max = root->left;
		else
			max = (root->left->n > root->right->n) ? root->left : root->right;

		if (root->n >= max->n)
			break;

		temp = root->n;
		root->n = max->n;
		max->n = temp;
		root = max;
	}
}

/**
 * get_last_node - get the last level-order node
 * @root: pointer to the root of the heap
 * @size: size of the heap
 *
 * Return: pointer to the last node
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
	int bit;
	size_t mask = 1;

	for (bit = 0; 1 << (bit + 1) <= (int)size; bit++)
		;
	for (bit--; bit >= 0; bit--)
	{
		mask = 1 << bit;
		if (size & mask)
			root = root->right;
		else
			root = root->left;
	}
	return (root);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 *
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node;
	size_t size;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	size = heap_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last_node = get_last_node(*root, size);

	(*root)->n = last_node->n;

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);

	heapify_down(*root);

	return (value);
}
