#include "binary_trees.h"
/**
 * binary_tree_delete - deletes entire binary tree
 * @tree: is a pointer to the root node that will be deleted
 */
void binary_tree_delete(binary_tree_t *tree)
{
	/* only do something if tree exists else do nothing */
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
