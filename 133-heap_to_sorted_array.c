#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers
 *		 NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	size_t heap_size, i;
	int extracted;

	if (!heap || !size)
		return (NULL);

	heap_size = binary_tree_size(heap);
	*size = heap_size;

	sorted_array = malloc(sizeof(int) * heap_size);
	if (!sorted_array)
		return (NULL);

	for (i = 0; i < heap_size; i++)
	{
		extracted = heap_extract(&heap);
		if (extracted == 0)
		{
			free(sorted_array);
			return (NULL);
		}
		sorted_array[i] = extracted;
	}

	return (sorted_array);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree
 *		 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
