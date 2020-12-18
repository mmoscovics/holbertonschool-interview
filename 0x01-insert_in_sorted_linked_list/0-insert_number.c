#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * insert_node - function to insert new node in a sorted list
 * @head: pointer to the beggining of the list
 * @number: data passed for new node
 * Return: address to the new node, or NULL if failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *pos = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;
	if (pos == NULL || number < pos->n)
	{
		new->next = *head;
		*head = new;
		return (*head);
	}
	while (pos)
	{
		if (pos->next)
		{
			if (number < pos->next->n || pos->next == NULL)
			{
				new->next = pos->next;
				pos->next = new;
				return (new);
			}
		}
		else
		{
			pos->next = new;
			return (new);
		}
		pos = pos->next;
	}
	return (NULL);
}
