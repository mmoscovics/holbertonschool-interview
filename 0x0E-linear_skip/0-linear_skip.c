#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of ints
 * @list: pointer to the head of the skip list
 * @value: value to search for
 * Return: pointer to the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp = list, *ex = list->express, *new;

	if (!list || !list->express)
		return (NULL);
	while (ex)
	{
		printf("Value checked at index [%lu] = [%d]\n", ex->index, ex->n);
		if (ex->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				temp->index, ex->index);
			break;
		}
		else if (ex->express == NULL)
		{
			new = ex;
			while (new->next != NULL)
				new = new->next;
			printf("Value found between indexes [%lu] and [%lu]\n",
				ex->index, new->index);
		}
		temp = ex;
		ex = ex->express;
	}
	while (temp != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", temp->index, temp->n);
		if (temp->n == value)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
