#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts doubly linked list of integers
 * in ascending order
 *
 * @list: doubly linked list listint_t
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *right;
	listint_t *left;
	int key;

	if (*list == NULL || (*list)->next == NULL || (*list)->next->next == NULL)
		return;

	left = *list;
	right = (*list)->next;

	while (right)
	{
		key = right->n;
		left = right->prev;

		while (left != NULL)
		{
			if (left->n > key)
			{
				swap_node(list, &left, right);
				print_list(*list);
			}
			left = left->prev;
		}
		right = right->next;
	}
}

/**
 * swap_node - Swaps two adjacent nodes left and right of doubly
 * linked list listint_t
 *
 * @list: The doubly linked list
 * @left: The left node
 * @right: The right node
 */
void swap_node(listint_t **list, listint_t **left, listint_t *right)
{
	listint_t *temp;

	temp = (*left)->prev;

	if (temp)
		(*left)->prev->next = right;
	else
		*list = right;

	right->prev = temp;
	(*left)->prev = right;
	(*left)->next = right->next;
	right->next = (*left);
	if ((*left)->next)
		(*left)->next->prev = (*left);
}
