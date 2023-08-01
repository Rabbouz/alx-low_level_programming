#include "lists.h"

/**
 * free_listint2 - A function that frees a linked list
 * @head: pointer
 *
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *tp;

	if if (head == NULL || *head == NULL)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

	*head = NULL;
}
