#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	int size = sizeof(*list), i = 0;
	listint_t *x;

	if (*list == NULL)
	{
		return;
	}
	while (i < size)
	{
		if (list[i] > list[i + 1])
		{
			x = list[i];
			list[i] = list[i + 1];
			list[i + 1] = x;
			i = 0;
			print_array(*list, size);
		}
		i++;
	}
}
