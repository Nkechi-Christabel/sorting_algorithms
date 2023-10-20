#include "sort.h"
#include <stdio.h>

/**
 * sift_down - Perform the sift-down operation to maintain the heap property.
 * @array: The array to be sorted as a heap.
 * @size: The size of the heap.
 * @root: The root of the current subtree.
 * @max_size: The maximum size of the heap.
 */
void sift_down(int *array, size_t size, size_t root, size_t max_size)
{
	size_t largest, left, right;
	int temp;

	largest = root;
	left = 2 * root + 1;
	right = 2 * root + 2;

	if (left < max_size && array[left] > array[largest])
		largest = left;

	if (right < max_size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;

		print_array(array, size);
		sift_down(array, size, largest, max_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int temp, i;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, (size_t)i, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		sift_down(array, size, 0, (size_t)i);
	}
}
