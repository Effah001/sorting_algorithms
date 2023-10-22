#include "sort.h"

/**
 * insertion_sort_list - Sorts integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while(current)
	{
		temp = current->prev;
		while (temp && temp->n > current->n)
		{
			if (temp->prev)
				temp->prev->next = current;
			if (current->next)
				current->next->prev = temp;

			temp->next = current->next;
			current->prev = temp->prev;

			current->next = temp;
			temp->prev = current;

			current->next = temp;
			temp->prev = current;

			if (current->prev == NULL)
				*list = current;

			temp = current->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
