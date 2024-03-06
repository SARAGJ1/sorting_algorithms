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
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current != NULL)
	{
		listint_t *temp = current->prev;

		while (temp != NULL && temp->n > current->n)
		{
			if (temp->prev != NULL)
			{
				temp->prev->next = current;
			}
			if (current->next != NULL)
			{
				current->next->prev = temp;
			}
			temp->next = current->next;
			current->prev = temp->prev;
			current->next = temp;
			temp->prev = current;
			if (current->prev == NULL)
			{
				*list = current;
			}
			print_list(*list);
			temp = current->prev;
		}
	current = current->next;
	}
}
