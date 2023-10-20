#include "sort.h"

/**
 * hoare_partition - Partitions an array using the Hoare partition scheme
 * @array: The array to be partitioned
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: The size of the array
 * Return: The pivot index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
		else
			return (j);
	}
}

/**
 * quickSort - Recursive function to perform Quick sort
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: The size of the array
 */
void quickSort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);
		quickSort(array, low, pivot, size);
		quickSort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 * Quick Sort (Hoare partition)
 * @array: The array to be sorted
 * @size: The size or length of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}
