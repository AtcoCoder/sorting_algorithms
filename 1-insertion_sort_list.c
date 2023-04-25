#include <stdio.h>
#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	listint_t *curr;
	listint_t *l_node;
	listint_t *r_node;

	curr = *list;
	l_node = curr;
	r_node = curr->next;

	while (curr)
	{
		while (curr->prev && l_node->n > r_node->n)
		{

		}
	}
}
