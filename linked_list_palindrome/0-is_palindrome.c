#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_list - Reverses a singly linked list
 * @head: Pointer to the head of the list
 * Return: Pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t **head)
{
    listint_t *prev = NULL, *curr = *head, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
    return (*head);
}
/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Pointer to the head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *prev_slow = *head;
    listint_t *second_half, *mid = NULL;
    int is_pal = 1;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    if (fast != NULL)
    {
        mid = slow;
        slow = slow->next;
    }

    second_half = slow;
    prev_slow->next = NULL;
    second_half = reverse_list(&second_half);

    while (second_half != NULL)
    {
        if ((*head)->n != second_half->n)
        {
            is_pal = 0;
            break;
        }
        *head = (*head)->next;
        second_half = second_half->next;
    }

    if (mid != NULL)
    {
        prev_slow->next = mid;
        mid->next = second_half;
    }
    else
        prev_slow->next = second_half;

    return (is_pal);
}
