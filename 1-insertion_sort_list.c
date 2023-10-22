#include "sort.h"

/**
 * insertion_sort_list - Sorts integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *unsorted = *list;
	listint_t  *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (unsorted)
	{
		current = unsorted;
		unsorted = unsorted->next;

		if (sorted == NULL || current->n < sorted->n)
		{
			current->next = sorted;
			current->prev = NULL;

			if (sorted)
			sorted->prev = current;

			sorted = current;
			*list = sorted;
		}
		else
		{
			temp = sorted;

			while (temp->next != NULL && current->n > temp->next->n)
				temp = temp->next;

			current->next = temp->next;
			current->prev = temp;

			if (temp->next != NULL)

			temp->next->prev = current;

			temp->next = current;
		}

		print_list(*list);
	}
}
