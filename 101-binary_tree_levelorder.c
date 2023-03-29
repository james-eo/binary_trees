#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - goes through a
 * binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	queue_t *queue = NULL;
	binary_tree_t *current_node;

	enqueue(&queue, (binary_tree_t *)tree);
	while (queue != NULL)
	{
		current_node = dequeue(&queue);
		func(current_node->n);

		if (current_node->left != NULL)
			enqueue(&queue, current_node->left);
		if (current_node->right != NULL)
			enqueue(&queue, current_node->right);
	}
}

/**
 * enqueue - add a binary tree node to the queue
 *
 * @queue: pointer to the queue
 * @node: pointer to the binary tree node to add
 *
 * Return: void
 */
void enqueue(queue_t **queue, binary_tree_t *node)
{
	queue_t *new_node = malloc(sizeof(queue_t));

	if (new_node == NULL)
		exit(EXIT_FAILURE);

	new_node->node = node;
	new_node->next = NULL;

	if (*queue == NULL)
	{
		*queue = new_node;
	}
	else
	{
		queue_t *last_node = *queue;

		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}

/**
 * dequeue - remove a binary tree node from the queue
 *
 * @queue: pointer to the queue
 *
 * Return: pointer to the binary tree node removed from the queue
 */
binary_tree_t *dequeue(queue_t **queue)
{
	if (*queue == NULL)
		return (NULL);

	binary_tree_t *node = (*queue)->node;
	queue_t *next_node = (*queue)->next;

	free(*queue);
	*queue = next_node;
	return (node);
}

