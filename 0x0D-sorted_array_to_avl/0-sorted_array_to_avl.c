#include "binary_trees.h"

/**
 * sorted_array_to_avl - Sorts and array to AVL tree
 * @array: Sorted array
 * @size: Size of array
 * Return: Head node to AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head = NULL;

	head = make_tree(NULL, array, 0, size - 1);
	if (head == NULL)
		return (NULL);
	return (head);
}

/**
 * make_tree - Creates AVL tree
 * @parent: Parent node
 * @array: Sorted array
 * @start: Start of sub array
 * @end: End of sub array
 * Return: Null on error or Root node
 */
avl_t *make_tree(avl_t *parent, int *array, int start, int end)
{
	int mid = 0;
	avl_t *root;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	root = make_node(parent, array[mid]);
	if (root == NULL)
		return (NULL);
	root->left = make_tree(root, array, start, mid - 1);
	root->right = make_tree(root, array, mid + 1, end);
	return (root);
}

/**
 * make_node - Creates new node
 * @parent: Parent of node
 * @value: Value for new
 * Return: New node
 */
avl_t *make_node(avl_t *parent, int value)
{
	avl_t *new = malloc(sizeof(avl_t));

	if (new == NULL)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	return (new);
}
