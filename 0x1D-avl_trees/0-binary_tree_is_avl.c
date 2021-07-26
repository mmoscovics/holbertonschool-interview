#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if given tree is an AVL tree
 * @tree: Tree
 * Return 1 if AVL, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (!tree)
		return (0);
	if (is_bst(tree, INT_MIN, INT_MAX) == 1)
	{
		l_height = tree_height(tree->left);
		r_height = tree_height(tree->right);
		if (abs(l_height - r_height) <= 1 &&
		    binary_tree_is_avl(tree->left) &&
		    binary_tree_is_avl(tree->right))
		    	return (1);
	}
	return (0);
}

/**
 * is_bst - Checks if given tree is a BST and its values are correct
 * @tree: Tree
 * @min: Min value
 * @max: Max value
 * Return: 1 if BST, otherwise 0
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

int tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (1);
	left = tree_height(tree->left);
	right = tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}
