/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 *
 * Return: Value stored in the root node
 *		 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node;
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
