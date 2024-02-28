#include "binary_trees.h"
/**
 * binary_tree_inorder - traverses tree using inorder traversal
 * @tree: a pointer to the root node
 * @func: a pointer to a function to call for each node.
 *
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	/* check for tree and func */
	if (!func || !tree)
		return;
	/* Recursively traverse left subtree */
	binary_tree_inorder(tree->left, func);
	/* Call the function for the current node */
	func(tree->n);
	/* Recursively traverse left subtree */
	binary_tree_inorder(tree->right, func);
}
