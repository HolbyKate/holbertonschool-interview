#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

/**
 * _print_error - Prints error and exits.
 */
void _print_error(void)
{
	if (write(2, "Error\n", 6) == -1)
	{
		// If writing to stderr fails, exit with a different code
		exit(99);
	}
	exit(98);
}

/**
 * _isdigit - Check if a string is composed only of digits.
 * @s: The string to check.
 * Return: 1 if digits only, 0 otherwise.
 */
int _isdigit(char *s)
{
	if (s == NULL)
		return (0);

	while (*s)
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

/**
 * _strlen - Returns the length of a string.
 * @s: The string whose length is to be calculated.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	if (s == NULL)
		return (0);

	while (s[len])
		len++;
	return (len);
}

/**
 * multiply - Multiplies two numbers represented as strings.
 * @num1: First number.
 * @num2: Second number.
 */
void multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1), len2 = _strlen(num2);
	int *result = calloc(len1 + len2, sizeof(int));
	int i, j, n1, n2, carry, sum;

	if (!result)
		_print_error();

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = (n1 * n2) + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}
		result[i + j + 1] += carry;
	}

	i = 0;
	while (i < len1 + len2 && result[i] == 0)
		i++;

	if (i == len1 + len2)
	{
		if (_putchar('0') == -1)
		{
			free(result);
			_print_error();
		}
	}
	else
	{
		for (; i < len1 + len2; i++)
			if (_putchar(result[i] + '0') == -1)
			{
				free(result);
				_print_error();
			}
	}
	if (_putchar('\n') == -1)
	{
		free(result);
		_print_error();
	}

	free(result);
}

/**
 * main - Entry point. Multiplies two numbers.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
		_print_error();

	multiply(argv[1], argv[2]);

	return (0);
}
