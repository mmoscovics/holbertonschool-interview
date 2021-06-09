#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void split_merge(int *a, size_t left, size_t right, int *b);
void merge(int *a, size_t left, size_t mid, size_t right, int *b);
void copy_array(int *a, size_t size, int *b);

#endif
