#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order.
 * @list: Double pointer to the head of the doubly linked list.
 *
 * Description: This function implements the insertion sort algorithm on a
 *              doubly linked list. It iterates through the list, and for each
 *              element, it moves the element to its correct position in the
 *              sorted part of the list. The list is sorted in-place.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	/* Check if list is NULL or if it only has one element */
	if (!list || !*list)
		return;

	/* Iterate through each element in the list starting from the second node */
	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			/* Swap nodes */
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			if (current->prev)
				current->prev->next = current;
			else
				*list = current;

			/* Print the list after each swap for visual tracking */
			print_list(*list);
		}
	}
}
