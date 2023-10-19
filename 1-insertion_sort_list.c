#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		next_node = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;

			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;

			if (current->next != NULL)
				current->next->prev = prev;

			prev->next = current->next;
			current->prev = prev->prev;
			prev->prev = current;
			current->next = prev;

			print_list(*list);

			if (current->prev == NULL)
				*list = current;
		}

	current = next_node;
	}
}
