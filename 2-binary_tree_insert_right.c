#include "binary_trees.h"
/**
 * binary_tree_insert_right - adds a node to the right of parent node
 * @parent: the parent node
 * @value: the value of the node
 * Return: pointer to the child node or NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	/* declarations */
	binary_tree_t *node;

	/* check for parent */
	if (!parent)
		return (NULL);
	/* calloc for node */
	node = calloc(1, sizeof(binary_tree_t));
	/* check for calloc fail */
	if (!node)
		return (NULL);
	/* assign values */
	node->n = value;
	node->parent = parent;
	if (parent->right)
	{
		/*Assign the current right child of parent to the right of new node*/
		node->right = parent->right;
		/*Update the parent pointer of the current right child to the new node*/
		node->right->parent = node;
	}
	parent->right = node;
	return (node);
}
