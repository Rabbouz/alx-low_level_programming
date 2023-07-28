#include <stdlib.h>
#include "lists.h"

/**
 * free_list - A function that frees a linked list
 * @head: list to be freed
 *Return: void
 */

void free_list(list_t *head)
{
	list_t *temp;

	for (; head; head = temp)
	{
		temp = head->next;
		free(head->str);
		free(head);
	}
}
