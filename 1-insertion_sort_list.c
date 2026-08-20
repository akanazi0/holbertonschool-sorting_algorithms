#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			tmp = current->prev;

			if (tmp->prev != NULL)
				tmp->prev->next = current;
			else
				*list = current;

			if (current->next != NULL)
				current->next->prev = tmp;

			current->prev = tmp->prev;
			tmp->next = current->next;
			current->next = tmp;
			tmp->prev = current;

			print_list(*list);
		}
		current = current->next;
	}
}
