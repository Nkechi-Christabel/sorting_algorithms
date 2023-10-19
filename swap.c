#include "sort.h"

/**
 * swap - Swaps the values of two integer pointers.
 * @ap: Pointer to the first integer.
 * @bp: Pointer to the second integer.
 */
void swap(int *ap, int* bp)
{
	int temp = *ap;
	*ap = *bp;
	*bp = temp;
}
