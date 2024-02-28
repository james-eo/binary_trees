#include "binary_trees.h"
/**
 * binary_tree_preorder - traverses a binary tree using pre-order traversal
 * @tree: the tree
 * @func: the fucntion call to make
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	/* if tree or func are NULL, return */
	if (tree == NULL || func == NULL)
		return;
	/* call the func for the corrent node */
	func(tree->n);
	/* Recursively traverse left subtree */
	binary_tree_preorder(tree->left, func);
	/* Recursively traverse right subtree */
	binary_tree_preorder(tree->right, func);
}
