#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * lint_t *list - checks if a singly linked list has a cycle
 * @head: Pointer to the head of the list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
    listint_t *slow, *fast;

    if (!list)
        return (0);

    slow = list;
    fast = list;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return (1);
        }
    }
    return (0);
}
