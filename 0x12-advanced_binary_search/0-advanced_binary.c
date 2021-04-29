#include "search_algos.h"

/**
 * advanced_binary - Function that searches using binary search
 * @array: pointer to the first element of array
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located otherwise -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array != NULL)
		return (searcher(array, 0, size - 1, value));
	return (-1);
}

/**
 * searcher - A recursive binary search function
 * @array: pointer to the first element of the array
 * @l: left position
 * @r: right position
 * @value: value to search for
 * Return: index where value is located or -1
 */

size_t searcher(int *array, size_t l, size_t r, int value)
{
	unsigned int mid;

	if (r >= l)
	{
		mid = (l + r) / 2;
		print_array(array, l, r);
		if (array[mid] == value)
		{
			if (array[mid - 1] == value)
				return (searcher(array, l, mid, value));
			return (mid);
		}
		else if (array[mid] > value)
			return (searcher(array, l, mid, value));
		else
			return (searcher(array, mid + 1, r, value));
	}
	return (-1);
}

/**
 * print_array - prints out array being searched
 * @array: array to print
 * @l: left position
 * @r: right position
 */

void print_array(int *array, size_t l, size_t r)
{
	unsigned int i;

	printf("Searching in array: ");
	for (i = l; i <= r; i++)
	{
		if (i != l)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
