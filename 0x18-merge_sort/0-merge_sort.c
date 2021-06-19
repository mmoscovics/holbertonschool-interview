#include "sort.h"

/**
 * merge_sort - sorts an array in ascending order using Top-down Merge sort
 * @array: array of integers
 * @size: size of array
 */

void merge_sort(int *array, size_t size)
{
	int *copy = malloc(sizeof(int) * size + 1);

	if (copy == NULL)
		return;
	if (array == NULL || size < 2)
	{
		free(copy);
		return;
	}
	split_merge(array, 0, size, copy);
	free(copy);
}

/**
 * split_merge - splits the given array into sub arrays
 * @A: array of integers
 * @left: left index
 * @right: right index
 * @B: temp array to copy to
 */

void split_merge(int *A, size_t left, size_t right, int *B)
{
	size_t mid;

	if (right - left < 2)
		return;
	mid = (right + left) / 2;
	split_merge(A, left, mid, B);
	split_merge(A, mid, right, B);
	merge(A, left, mid, right, B);
}

/**
 * merge - function that prints and merges sub arrays
 * @A: array of integers
 * @left: left index
 * @mid: middle index
 * @right: right index
 * @B: temp array to copy to
 */

void merge(int *A, size_t left, size_t mid, size_t right, int *B)
{
	size_t l = left, m = mid, i;

	printf("Merging...\n[left]: ");
	print_array(&A[left], mid - left);
	printf("[right]: ");
	print_array(&A[mid], right - mid);

	for (i = left; i <= right; i++)
	{
		if (l < mid && (m >= right || A[l] <= A[m]))
		{
			B[i] = A[l];
			l++;
		}
		else
		{
			B[i] = A[m];
			m++;
		}
	}
	copy_array(A, right, B);
	printf("[Done]: ");
	print_array(&A[left], right - left);
}

/**
 * copy_array - copies array to temporary array
 * @A: array of integers
 * @size: size of array
 * @B: temp array to copy to
 */

void copy_array(int *A, size_t size, int *B)
{
	size_t i;

	for (i = 0; i < size; i++)
		A[i] = B[i];
}