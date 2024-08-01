#include "binary_trees.h"

/**
 * heap_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree
 *		 0 if tree is NULL
 */
size_t heap_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * heapify_down - Restores the Max Binary Heap property
 * @root: Pointer to the root of the heap
 */
void heapify_down(binary_tree_t *root)
{
	binary_tree_t *largest = root;
	binary_tree_t *left = root->left;
	binary_tree_t *right = root->right;

	if (left && left->n > largest->n)
		largest = left;

	if (right && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		int temp = root->n;

		root->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

/**
 * get_last_node - Gets the last level-order node of the heap
 * @root: Pointer to the root of the heap
 * @size: Size of the heap
 *
 * Return: Pointer to the last node
 */
binary_tree_t *get_last_node(binary_tree_t *root, size_t size)
{
	size_t mask = 1;

	while (mask <= size)
		mask <<= 1;
	mask >>= 2;

	while (mask > 0)
	{
		if (size & mask)
			root = root->right;
		else
			root = root->left;
		mask >>= 1;
	}
	return (root);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 *
 * Return: Value stored in the root node
 *		 0 on failure
 */
int heap_extract(binary_tree_t **root)
{
	int value;
	binary_tree_t *last_node;
	size_t size;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	size = heap_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last_node = get_last_node(*root, size);

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	last_node->left = (*root)->left;
	last_node->right = (*root)->right;
	last_node->parent = NULL;

	if (last_node->left)
		last_node->left->parent = last_node;
	if (last_node->right)
		last_node->right->parent = last_node;

	free(*root);
	*root = last_node;

	heapify_down(*root);

	return (value);
}
