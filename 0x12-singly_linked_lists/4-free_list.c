#include <stdlib.h>
#include "lists.h"

/**
 * free_list - A function that frees a linked list
 * @head: list to be freed
 */
void free_list(list_t *head)
{
	list_t *tp;

	while (head)
	{
		tp = head->next;

		while (head->str != NULL)
		{
			free(head->str);
		}

		free(head);
		head = tp;
	}
}
