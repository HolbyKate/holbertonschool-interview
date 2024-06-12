#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

struct Node
{
	int data;
	struct Node *next;
};

struct node *head, *tail = NULL;
int size = 0;

/**
 * is_palindrome_Recursive_Helper- checks if a palindrome using recursion
 * @left: start at the head
 * @right:
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome_Recursive_Helper(listint_t **left, listint_t **right)
{}

int is_palindrome(listint_t **head)
{

	if (is_palindrome == 1)
		printf("Linked list is a palindrome\n");
	else
		printf("Linked list is not a palindrome\n");

	free_listint(head);

	return (0);
}
