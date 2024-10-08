#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list.
 * @head: Double pointer to the head of the list.
 * @n: Integer value for the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

    new_node = (listint_t *)malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	size_t count = 0;

	while (current)
	{
		custom_print(current->n);
        count++;
        current = current->next;
	}
	return (count);
}

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: Double pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *temp;

	while (*h)
	{
		temp = *h;
		*h = (*h)->next;
		free(temp);
		count++;
	}
	return (count);
}

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The address of the node where the loop starts, or NULL if no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise = head;
	listint_t *hare = head;

	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
			break;
	}

	if (hare == NULL || hare->next == NULL)
		return (NULL);

	tortoise = head;
	while (tortoise != hare)
	{
		tortoise = tortoise->next;
		hare = hare->next;
	}

	return (tortoise);
}
