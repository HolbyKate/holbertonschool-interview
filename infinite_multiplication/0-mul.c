#include "holberton.h"
#include <stdlib.h>

/**
 * main - Multiplies two positive numbers.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	validate_input(argc, argv);

	char *num1 = argv[1];
	char *num2 = argv[2];
	char *result = multiply_numbers(num1, num2);

	if (!result)
		_print_error();

	print_result(result, get_length(result));

	free(result);
	return (0);
}

/**
 * _print_error - Prints an error message and exits with status 98.
 */
void _print_error(void)
{
	char *error = "Error\n";

	while (*error)
	{
		_putchar(*error);
		error++;
	}
	exit(98);
}

/**
 * is_digit - Checks if a string is composed of only digits.
 * @s: The string to check.
 *
 * Return: 1 if all characters are digits, 0 otherwise.
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _calloc - Allocates memory for an array using malloc and sets it to zero.
 * @nmemb: Number of elements in the array.
 * @size: Size of each element.
 *
 * Return: Pointer to the allocated memory or NULL if it fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		p[i] = 0;

	return (p);
}

/**
 * validate_input - Validates the input arguments.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 */
void validate_input(int argc, char *argv[])
{
	if (argc != 3)
		_print_error();

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
		_print_error();
}

/**
 * get_length - Returns the length of a string.
 * @s: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int get_length(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * multiply_numbers - Multiplies two numbers given as strings.
 * @num1: The first number.
 * @num2: The second number.
 *
 * Return: Pointer to the resulting string of the multiplication.
 */
char *multiply_numbers(char *num1, char *num2)
{
	int len1 = get_length(num1);
	int len2 = get_length(num2);
	int len_res = len1 + len2;
	char *result = _calloc(len_res + 1, sizeof(char));
	int i, j, carry, prod;

	if (result == NULL)
		return (NULL);

	for (i = 0; i < len_res; i++)
		result[i] = '0';

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			prod = (num1[i] - '0') * (num2[j] - '0') +
				   (result[i + j + 1] - '0') + carry;

			carry = prod / 10;
			result[i + j + 1] = (prod % 10) + '0';
		}
		result[i + j + 1] += carry;
	}

	return (result);
}

/**
 * print_result - Prints the result of the multiplication.
 * @result: The result string.
 * @len_res: Length of the result string.
 */
void print_result(char *result, int len_res)
{
	int i = 0;

	while (i < len_res && result[i] == '0')
		i++;

	if (i == len_res)
		_putchar('0');
	else
	{
		while (i < len_res)
			_putchar(result[i++]);
	}
	_putchar('\n');
}
