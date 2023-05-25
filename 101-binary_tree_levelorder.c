#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t const **queue;
	size_t front, back;

	/* Make sure tree and func are not NULL */
	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(*queue) * binary_tree_height(tree));
	if (queue == NULL)
		return;

	front = 0;
	back = 1;
	queue[0] = tree;

	while (front < back)
	{
		binary_tree_t const *node = queue[front++];

		func(node->n);
		if (node->left != NULL)
		{
			queue[back++] = node->left;
		}
		if (node->right != NULL)
		{
			queue[back++] = node->right;
		}
	}

	free(queue);
}
