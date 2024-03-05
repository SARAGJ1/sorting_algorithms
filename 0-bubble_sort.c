#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *
 * Return: print array after each time you swap two elements
 */

void bubble_sort(int *array, size_t size)
{
	int x = 0;
	size_t i, j;

	for (j = 0; j <= size; j++)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] > array[i + 1])
			{
				x = array[i];
				array[i] = array[i + 1];
				array[i + 1] = x;
				print_array(array, size);
			}
			else
			{
				i++;
			}
		}
	}
}
