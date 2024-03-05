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
	int y;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		k = i;
		y = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[k] > array[j])
			{
				k = j;
				y = array[j];
			}
		}
		if (y != 0)
		{
			array[k] = array[i];
			array[i] = y;
		}
		print_array(array, size);
	}
}	
