#include "binary_trees.h"

/**
 * this function that creates a binary tree node
 * @parent: the parent tree
 * @value: the value of the parent tree
 * Retrun: NULL if unable to allocate memory, else new_node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

