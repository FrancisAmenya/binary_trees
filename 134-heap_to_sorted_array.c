#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array-integer.
 *
 * @heap: A pointer to the root node of the heap to convert.
 * @size: An address to store the size of the array.
 *
 * Return: Sorted in descending order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	int extract, i = 0;
	size_t heap_size_value;

	if (!heap || !size)
		return (NULL);

	heap_size_value = heap_size((const binary_tree_t *)heap);
	*size = heap_size_value;

	array = malloc(heap_size_value * sizeof(int));
	if (!array)
		return (NULL);

	while (heap)
	{
		extract = heap_extract((binary_tree_t **)&heap);
		array[i] = extract;
		i++;
	}

	return (array);
}
