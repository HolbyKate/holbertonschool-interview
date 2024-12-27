// function that finds all the possible substrings containing
//a list of words, within a given string.

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
 * Returns: 1 if the substring is valid, 0 otherwise.
 */
static int validate_substring(const char *s, int start, int word_len, int nb_words, const char **words) {
	int i, j;
	int *used_words = (int *)malloc(sizeof(int) * nb_words);

	if (!used_words) {
		return 0;
	}

	memset(used_words, 0, sizeof(int) * nb_words);

	for (i = 0; i < nb_words; i++) {
		for (j = 0; j < nb_words; j++) {
			// Check if the word has not been used and matches the current substring
			if (!used_words[j] && strncmp(s + start + i * word_len, words[j], word_len) == 0) {
				used_words[j] = 1; // Mark the word as used
				break;
			}
		}
		// If no matching word is found, the substring is invalid
		if (j == nb_words) {
			free(used_words);
			return 0;
		}
	}

	free(used_words);
	return 1; // Substring is valid
}

/**
 * find_substring - Finds all substrings that are exact concatenations
 * of the words in "words".
 * @s: The string to analyze.
 * @words: Array of words used to form substrings.
 * @nb_words: Total number of words.
 * @n: Pointer to store the number of valid substrings found.
 *
 * Returns: Array of starting indices of valid substrings, or NULL if none.
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n) {
	int word_len, s_len, i, *indices, index_count = 0;

	if (!s || !words || nb_words == 0) {
		return NULL; // Invalid parameters
	}

	word_len = strlen(words[0]);
	s_len = strlen(s);

	if (s_len < word_len * nb_words) {
		return NULL; // String is too short to contain a concatenation
	}

	// Allocate memory to store the indices of valid substrings
	indices = (int *)malloc(sizeof(int) * (s_len - word_len * nb_words + 1));
	if (!indices) {
		return NULL; // Memory allocation failed
	}

	for (i = 0; i <= s_len - word_len * nb_words; i++) {
		if (validate_substring(s, i, word_len, nb_words, words)) {
			indices[index_count++] = i; // Record the starting index
		}
	}

	if (index_count == 0) {
		free(indices);
		return NULL; // No valid substrings found
	}

	*n = index_count; // Update the number of substrings found
	return indices;
}
