#ifndef SORT_H
#define SORT_H


#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t heap_size, unsigned int idx, size_t size);
void swap(int *array, size_t size, int *a, int *b);

#endif
