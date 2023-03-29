#include "binary_trees.h"

/**
  * binary_tree_node - Create a new node of a Binary tree
  * @parent: node parent
  * @value: key to insert in the new node
  * Return: the address of the new node
  */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
