#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k = 0;
	int y = 0, l;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		k = i;
		l = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[k] > array[j])
			{
				k = j;
				l = 1;
			}
		}
		y = array[k];
		array[k] = array[i];
		array[i] = y;
		if (l != 0)
		{
			print_array(array, size);
		}
	}
}
