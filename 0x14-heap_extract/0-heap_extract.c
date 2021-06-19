#include "binary_trees.h"

/**
 * heap_extract - extracts root node of a max binary heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 on fail
 */
int heap_extract(heap_t **root)
{
	int temp, depth = 0;
	heap_t *current = *root, *left_depth, *swap;

	if (!root || !(*root))
		return (0);
	temp = (*root)->n;
	current = extract(current);
	while ((*root)->parent)
		*root = (*root)->parent;
	for (left_depth = *root; left_depth->left; left_depth = left_depth->left)
		depth += 1;
	swap = find_right(*root, 1, depth);
	if (current != swap)
		swap_root(swap, current);
	if (!depth)
		*root = NULL;
	remove_root(current);
	return (temp);
}

/**
 * extract - moves root to the end for removal
 * @root: root node
 * Return: root node for removal
 */
heap_t *extract(heap_t *root)
{
	heap_t *right = root->right ? root->right : NULL;
	heap_t *left = root->left ? root->left : NULL;
	heap_t *hold = NULL, *swap = NULL;
	int temp;

	if (left && right)
		hold = (left->n >= right->n) ? left : right;
	else if (left || right)
		hold = left ? left : right;
	else
		return (root);
	temp = hold->n;
	hold->n = root->n;
	root->n = temp;
	swap = hold;
	hold = root;
	root = swap;
	return (extract(root));
}

/**
 * find_right - finds right node in binary tree to remove
 * @root: root or starting node
 * @depth: depth of tree
 * @target: target or max depth
 * Return: next node to remove
 */
heap_t *find_right(heap_t *root, int depth, int target)
{
	heap_t *right = root->right ? root->right : NULL;
	heap_t *left = root->left ? root->left : NULL;
	heap_t *temp = root;

	if (target == 0)
		return (root);
	if (depth == target)
	{
		if (right)
			return (right);
		else if (left)
			return (left);
		else
			return (NULL);
	}
	else if (left && right)
	{
		temp = find_right(right, depth + 1, target);
		if (temp == NULL)
			temp = find_right(left, depth + 1, target);
	}
	else
		return (NULL);
	return (temp);
}

/**
 * swap_root - swaps root and node
 * @point1: root node
 * @point2: node to swap
 */
void swap_root(heap_t *point1, heap_t *point2)
{
	heap_t *p1 = point1->parent ? point1->parent : NULL;
	heap_t *p2 = point2->parent ? point2->parent : NULL;

	if (p1)
	{
		if (p1->left == point1)
			p1->left = point2;
		else
			p1->right = point2;
	}
	if (p2)
	{
		if (p2->left == point2)
			p2->left = point1;
		else
			p2->right = point1;
	}
	point1->parent = p2;
	point2->parent = p1;
}

/**
 * remove_root - removes node from the binary tree
 * @point: node to be removed
 */
void remove_root(heap_t *point)
{
	heap_t *left, *parent = point->parent ? point->parent : NULL;

	if (point->parent)
	{
		left = parent->left ? parent->left : NULL;
		if (left && left == point)
			parent->left = NULL;
		else
			parent->right = NULL;
	}
	free(point);
}
