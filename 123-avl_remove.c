#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove from the tree
 * Return: Pointer to the new root node of the tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left ? root->left : root->right;
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
			{
				*root = *temp;
			}
			free(temp);
		}
		else
		{
			temp = root->right;
			while (temp->left != NULL)
				temp = temp->left;
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}
	if (root == NULL)
		return (NULL);
	if (binary_tree_balance(root) < -1 || binary_tree_balance(root) > 1)
		return (root);
	return (root);
}
