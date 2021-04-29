#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

/* HEADERS */
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPES */
int advanced_binary(int *array, size_t size, int value);

/* HELPER FUNCTIONS */
size_t searcher(int *array, size_t l, size_t r, int value);
void print_array(int *array, size_t l, size_t r);

#endif /* SEARCH_ALGOS_H */