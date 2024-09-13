#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h> /* For size_t */

/* Function Prototypes */
int advanced_binary(int *array, size_t size, int value);
void print_array(int *array, size_t left, size_t right);
int recursive_binary(int *array, size_t left, size_t right, int value);

#endif /* SEARCH_ALGOS_H */