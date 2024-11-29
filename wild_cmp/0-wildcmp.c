#include "holberton.h"
#include <stdio.h>

/**
* wildcmp - Compares two strings
 * @s1: string 1
 * @s2: string 2 with wildcards
 *
 *  Return: 1 if strings are identical, otherwise return 0
 */

int wildcmp(char *s1, char *s2)
{
    // If empty it match
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    // If we find a '*' in s2
    if (*s2 == '*')
    {
        if (*(s2 + 1) == '*')
            return (wildcmp(s1, s2 + 1));

        // 1. '*' matches empty string: skip '*' in s2
        if (wildcmp(s1, s2 + 1))
            return (1);
        // 2. '*' matches current char in s1: keep '*' and move s1
        if (*s1 != '\0' && wildcmp(s1 + 1, s2))
            return (1);
        return (0);
    }

    // If current characters match, go to next characters
    if (*s1 == *s2)
        return (wildcmp(s1 + 1, s2 + 1));

    return (0);
}