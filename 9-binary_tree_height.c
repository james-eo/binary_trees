#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure
 *Return: size_t height or 0
 *
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* declarations */
	size_t left_height, right_height;

	/* tree is null or a loner */
	if (!tree || (!tree->left && !tree->right))
		return (0);
	/* measure both left and right subtrees recursively */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	/* compare and return tallest */
	return ((left_height > right_height ? left_height : right_height) + 1);
}
