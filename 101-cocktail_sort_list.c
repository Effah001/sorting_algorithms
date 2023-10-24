#include "sort.h"

/**
 * cocktail_sort_list - sorts an array using cocktail sort
 * @list: pointer to the head of the list
 *
 */

void cocktail_sort_list(listint_t **list)
{
	int swp = 1;
	listint_t *start = *list;
	listint_t *end = NULL;

	if (!list || *list || !(*list)->next)
		return;

	while (swp)
	{
		swp = 0;

		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(start, start->next);
				if (start->prev == NULL)
					*list = start;
				print_list(*list);
				swp = 1;
			}
			else
			{
				start = start->next;
			}
		}

		if (!swp)
			break;
		swp = 0;
		end = start;
		start = start->prev;

		while (start->prev)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(start->prev, start);
				if (start->prev == NULL)
					*list = start;
				print_list(*list);
				swp = 1;
			}
			else
				start = start->prev;
		}

	}
}


/**
 * swap_nodes - swaps two nodes
 * @first: first node
 * @second: second node
 *
 */

void swap_nodes(listint_t *first, listint_t *second)
{
	if (first->prev)
		first->prev->next = second;
	if (second->next)
		second->next->prev = first;

	first->next = second->next;
	second->prev = first->prev;

	first->prev = second;
	second->next = first;

	if (first->next)
		first->next->prev = first;
	if (second->prev)
		second->prev->next = second;
}
