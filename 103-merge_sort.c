#include "sort.h"

void merge(int *array, int *left, int left_size, int *right, int right_size);
void merge_sort_recursive(int *array, int *temp, size_t size);

/**
 * merge - Merge two subarrays into a single sorted array.
 * @array: The original array containing the subarrays.
 * @left: The left subarray.
 * @left_size: The size of the left subarray.
 * @right: The right subarray.
 * @right_size: The size of the right subarray.
 */
void merge(int *array, int *left, int left_size, int *right, int right_size)
{
	int i, j, k;

	i = j = k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}
}

/**
 * merge_sort_recursive - Recursively sorts an array using the merge sort
 * @array: The array to be sorted.
 * @temp: Temporary storage for merging.
 * @size: The size of the array.
 */
void merge_sort_recursive(int *array, int *temp, size_t size)
{
	size_t middle;
	int *left = array;
	int *right;
	size_t i;

	if (size <= 1)
		return;

	middle = size / 2;
	right = array + middle;

	merge_sort_recursive(left, temp, middle);
	merge_sort_recursive(right, temp, size - middle);

	printf("Merging...\n[left]: ");
	for (i = 0; i < middle; i++)
	{
		printf("%d", left[i]);
		if (i < middle - 1)
		{
			printf(", ");
		}
	}
	printf("\n[right]: ");
	for (i = 0; i < size - middle; i++)
	{
		printf("%d", right[i]);
		if (i < size - middle - 1)
		{
			printf(", ");
		}
	}
	printf("\n");

	merge(temp, left, middle, right, size - middle);
	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}

	printf("[Done]: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge Sort
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp = malloc(size * sizeof(int));

	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, size);
	free(temp);
}
