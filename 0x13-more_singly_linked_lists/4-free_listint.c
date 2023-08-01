#include "lists.h"

/**
 * free_listint - A function that frees a linked list
 * @head: list to be freed(listoint_t)
 *
 * Return: void
 */

void free_listint(listint_t *head)
{
	listint_t *tp;

	while (head != NULL)
	{
		tp = head;
		head = head->next;
		free(tp);
	}
}
