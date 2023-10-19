#include "sort.h"

/**
 * swap - Swaps the values of two integer pointers.
 * @ap: Pointer to the first integer.
 * @bp: Pointer to the second integer.
 */
void swap(int *ap, int *bp)
{
	int temp = *ap;
	*ap = *bp;
	*bp = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 * Bubble sort algorithm.
 * @array: The array to sort.
 * @size: Length of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			swapped = 0;
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
			break;
	}
}
