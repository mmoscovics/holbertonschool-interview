#include "list.h"

/**
 * add_node_end - adds node to the end of list
 * @list: list to modify 
 * @str: string to copy to new node
 * Return: Address of new node or NULL
 */
List *add_node_end(List **list, char *str)
{
	List *temp, *new;

	if (!str)
		return (NULL);
	new = create_node(str);
	if (!new)
		return (NULL);
	if (!*list)
	{
		*list = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		temp = (*list)->prev;
		temp->next = new;
		new->next = *list;
		new->str = str;
		(*list)->prev = new;
		new->prev = temp;
	}
	return (new);
}

/**
 * add_node_begin - adds node to the beginning of list
 * @list: list to modify 
 * @str: string to copy to new node
 * Return: Address of new node or NULL
 */
List *add_node_begin(List **list, char *str)
{
	List *temp, *new;

	if (!str)
		return (NULL);
	new = create_node(str);
	if (!new)
		return (NULL);
	if (!*list)
	{
		*list = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		temp = (*list)->prev;
		temp->next = new;
		new->prev = temp;
		(*list)->prev = new;
		new->next = *list;
		*list = new;
	}
	return (new);
}

/**
 * create_node - creates new node with string
 * @str: string to add to node
 * Return: address of node or NULL
 */
List *create_node(char *str)
{
	List *new = malloc(sizeof(List));

	if (!new)
		return (NULL);
	new->str = strdup(str);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
