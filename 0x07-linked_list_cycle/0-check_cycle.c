#include "lists.h"

/**
 * check_cycle - function that checks is a single linked list has a cycle
 * @list: pointer to start of a linked list
 * Return: 0 is there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *fast = list, *slow = list;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return (1);
	}
	return (0);
}
