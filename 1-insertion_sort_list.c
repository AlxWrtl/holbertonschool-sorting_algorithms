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
	listint_t *current, *swap;

	/* Check if list is NULL or if it only has one element */
	if (!list || !*list)
		return;

	/* Iterate through each element in the list starting from the second node */
	for (current = (*list)->next; current != NULL; current = current->next)
	{
		/* Iterate through the sorted part of the list */
		while (current->prev && current->n < current->prev->n)
		{
			swap = current->prev;

			/* Detaching the current node from its position */
			current->prev = swap->prev;
			swap->next = current->next;

			/* Adjusting links of the surrounding nodes */
			if (swap->prev)
				swap->prev->next = current;
			if (current->next)
				current->next->prev = swap;

			/* Finalizing the swap of the nodes */
			current->next = swap;
			swap->prev = current;

			/* Update the head of the list if current is the new first node */
			if (!current->prev)
				*list = current;

			/* Print the list after each swap for visual tracking */
			print_list(*list);
		}
	}
}
