#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "substring.h"

/**
 * validate_substring - Checks if a substring starting at "start" is a
 * valid concatenation of the given words in "words".
 * @s: The string to check.
 * @start: The starting index of the substring.
 * @word_len: The length of each word.
 * @nb_words: The total number of words.
 * @words: The array of words.
 *
 * Return: 1 if the substring is valid, 0 otherwise.
 */
static int validate_substring(const char *s, int start, int word_len,
		int nb_words, const char **words)
{
	int i, j;
	int *used_words = (int *)malloc(sizeof(int) * nb_words);

	if (!used_words)
		return (0);

	memset(used_words, 0, sizeof(int) * nb_words);

	for (i = 0; i < nb_words; i++)
	{
		for (j = 0; j < nb_words; j++)
		{
			if (!used_words[j] &&
					strncmp(s + start + i * word_len, words[j], word_len) == 0)
			{
				used_words[j] = 1;
				break;
			}
		}
		if (j == nb_words)
		{
			free(used_words);
			return (0);
		}
	}

	free(used_words);
	return (1);
}

/**
 * find_substring - Finds all substrings that are exact concatenations
 * of the words in "words".
 * @s: The string to analyze.
 * @words: Array of words used to form substrings.
 * @nb_words: Total number of words.
 * @n: Pointer to store the number of valid substrings found.
 *
 * Return: Array of starting indices of valid substrings, or NULL if none.
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
	int word_len, s_len, i, *indices, index_count = 0;

	if (!s || !words || nb_words == 0)
		return (NULL);

	word_len = strlen(words[0]);
	s_len = strlen(s);

	if (s_len < word_len * nb_words)
		return (NULL);

	indices = (int *)malloc(sizeof(int) * (s_len - word_len * nb_words + 1));
	if (!indices)
		return (NULL);

	for (i = 0; i <= s_len - word_len * nb_words; i++)
	{
		if (validate_substring(s, i, word_len, nb_words, words))
		{
			indices[index_count++] = i;
		}
	}

	if (index_count == 0)
	{
		free(indices);
		return (NULL);
	}

	*n = index_count;
	return (indices);
}
