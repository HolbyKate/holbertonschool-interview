#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - checks integer is a palindrome
 * @n: The number to be checked
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
    unsigned long original = n;
    unsigned long reserved = 0;

    while (n != 0)
    {
        reserved = reserved * 10 + n % 10;
        n /= 10;
    }

    return (original == reserved);
}
