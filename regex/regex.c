#include "regex.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * regex_match_recursive - checks whether a given pattern matches given string
 * @str: String to match
 * @pattern: Pattern to match
 * Return: 1 if matches, else 0
 */


int regex_match_recursive(char const *str, char const *pattern) {
	/* At the end, we have a match */
	if (*pattern == '\0')
		return (*str == '\0');

	int has_star = (pattern[1] == '*');

	/* If there is no star process pattern*/
	if (!has_star) {
		/* If str is empty or characters don't match (accounting for '.') */
		if (*str == '\0' || (*pattern != '.' && *pattern != *str))
			return 0;
		/* Return next character */
		return regex_match_recursive(str + 1, pattern + 1);
	}

	if (regex_match_recursive(str, pattern + 2))
		return 1;

	/* while try one or more characters */
	while (*str != '\0' && (*pattern == '.' || *pattern == *str)) {
		if (regex_match_recursive(str + 1, pattern))
			return 1;
		str++;
	}

	return 0;
}


