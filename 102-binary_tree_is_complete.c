#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: none
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Check if the tree or function pointer is NULL */
	if (tree == NULL || func == NULL)
		return;

	/* Create a queue to store nodes for level-order traversal */
	queue_t *queue = NULL;

	/* Enqueue the root node to the queue */
	enqueue(&queue, (void *)tree);

	/* Loop through all nodes in the queue */
	while (queue != NULL)
	{
		/* Dequeue the front node from the queue */
		const binary_tree_t *node = (const binary_tree_t *)dequeue(&queue);

		/* Call the function on the node value */
		func(node->n);

		/* Enqueue the left child node to the queue */
		if (node->left != NULL)
			enqueue(&queue, (void *)(node->left));

		/* Enqueue the right child node to the queue */
		if (node->right != NULL)
			enqueue(&queue, (void *)(node->right));
	}

	/* Free the queue after traversal */
	free_queue(queue);
}

