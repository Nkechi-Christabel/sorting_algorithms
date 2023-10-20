#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sorts - Sorts an array using counting sort
 * for a specific digit place.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The current exponent (digit place) to consider.
 */
void counting_sorts(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	int i;

	if (!output)
		return;

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using LSD Radix Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max_val;
	size_t i;
	int exp;

	if (!array || size < 2)
		return;

	max_val = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max_val)
		{
			max_val = array[i];
		}
	}

	for (exp = 1; max_val / exp > 0; exp *= 10)
	{
		counting_sorts(array, size, exp);
		print_array(array, size);
	}
}
