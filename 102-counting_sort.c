#include "sort.h"

/**
 * counting_sort - Corts an array of integers in ascending order using the
 * Counting sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size or length of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *sorted, i, max_num = 0;

	if  (size < 2)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
	}
	count_arr = malloc((max_num + 1) * sizeof(int));
	if (count_arr == NULL)
		return;

	for (i = 0; i <= max_num; i++)
		count_arr[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_arr[array[i]]++;
	for (i = 0; i <= max_num; i++)
		count_arr[i] += count_arr[i - 1];

	print_array(count_arr, max_num + 1);
	sorted = malloc(size * sizeof(int));
	if (sorted == NULL)
	{
		free(count_arr);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		sorted[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count_arr);
}
