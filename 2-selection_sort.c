#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size or length of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if ((size_t)min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
