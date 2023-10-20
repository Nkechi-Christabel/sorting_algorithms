#include "sort.h"

/**
 * counting_sort - Corts an array of integers in ascending order using the
 * Counting sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size or length of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, i, max_num = 0;
	size_t j, output_idx = 0;

	if (size < 2)
		return;

	for (j = 1; j < size; j++)
	{
		if (array[j] > max_num)
			max_num = array[j];
	}
	/*
	 Create a count array to store the number of occurrences of each
	 element in the array
	 */
	count_arr = malloc((max_num + 1) * sizeof(int));

	if (count_arr == NULL)
		return;
	/* Initialize the array with zeros */
	for (i = 0; i <= max_num; i++)
		count_arr[i] = 0;

	/* Count the number of occurrences of each element in the input array. */
	for (j = 0; j < size; j++)
		count_arr[array[j]]++;

	print_array(count_arr, max_num + 1);

	/* Sort the array in ascending order using the count array */
	for (i = 0; i <= max_num; i++)
	{
		while (count_arr[i] > 0)
		{
			array[output_idx] = i;
			output_idx++;
			count_arr[i]--;
		}
	}
	free(count_arr);
}
