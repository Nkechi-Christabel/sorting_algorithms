#include "sort.h"

/**
 * counting_sort - Corts an array of integers in ascending order using the
 * Counting sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size or length of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *sorted, i, max_num;
	size_t j;

	if  (size < 2)
		return;

	for (max_num = j = 0; j < size; j++)
	{
		if (array[j] > max_num)
			max_num = array[j];
	}
	count_arr = malloc((max_num + 1) * sizeof(int));
	if (count_arr == NULL)
		return;

	for (i = 0; i <= max_num; i++)
		count_arr[i] = 0;
	for (j = 0; j < size; j++)
		count_arr[array[j]]++;
	for (i = 0; i <= max_num; i++)
		count_arr[i] += count_arr[i - 1];

	print_array(count_arr, max_num + 1);
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
		free(count_arr);
		return;
	}
	for (j = 0; j < size; j++)
	{
		sorted[count_arr[array[j] - 1]] = array[j];
		count_arr[array[j]]--;
	}
	for (j = 0; j < size; j++)
		array[j] = sorted[j];

	free(sorted);
	free(count_arr);
}
