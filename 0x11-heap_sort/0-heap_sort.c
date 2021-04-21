#include "sort.h"

/**
 * heap_sort - Heap Sort function
 * @array: Head of Array to be sorted
 * @size: Size of Array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i > 0; i--)
	{
		swap(array, size, &array[0], &array[i]);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - Puts array in heap form
 * @array: Array to turn into heap
 * @hsize: Size of Heap
 * @idx: Index point of the heap
 * @size: Size of Array
 */
void heapify(int *array, size_t hsize, unsigned int idx, size_t size)
{
	unsigned int largest, left, right;

	largest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;
	if (left < hsize && array[left] > array[largest])
		largest = left;
	if (right < hsize && array[right] > array[largest])
		largest = right;
	if (largest != idx)
	{
		swap(array, size, &array[idx], &array[largest]);
		heapify(array, hsize, largest, size);
	}
}

/**
 * swap - Swap 2 values
 * @array: Given Array
 * @size: Size of Array
 * @a: First Value
 * @b: Second Value
 */
void swap(int *array, size_t size, int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, size);
}
