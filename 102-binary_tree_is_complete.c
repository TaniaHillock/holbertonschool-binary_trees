#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree, or 0 if tree is NUL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t const **queue;
	size_t front, back;
	int non_full_node_encountered = 0;

	if (tree == NULL)
		return (0);

	queue = malloc(sizeof(*queue) * binary_tree_height(tree));
	if (queue == NULL)
		return (0);

	front = 0;
	back = 1;
	queue[0] = tree;

	while (front < back)
	{
		binary_tree_t const *node = queue[front++];

		if (node->left != NULL)
		{
			if (non_full_node_encountered)
			{
				free(queue);
				return (0);
			}
			queue[back++] = node->left;
		}
		else
			non_full_node_encountered = 1;

		if (node->right != NULL)
		{
			if (non_full_node_encountered)
			{
				free(queue);
				return (0);
			}
			queue[back++] = node->right;
		}
		else
			non_full_node_encountered = 1;
	}

	free(queue);
	return (1);
}
