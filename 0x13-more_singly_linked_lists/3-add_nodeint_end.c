#include "lists.h"
/**
 * add_nodeint_end - A function that adds
 * a node at the end of a linked list
 * @head: pointer
 * @n: data to be inserted
 *
 * Return: pointer ,NULL if failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_n = malloc(sizeof(listint_t));

	listint_t *tp = *head;

	if (!new_n)
		return (NULL);

	new_n->n = n;
	new_n->next = NULL;

	if (*head == NULL)
	{
		*head = new_n;
		return (new_n);
	}

	while (tp->next)
		tp = tp->next;

	tp->next = new_n;

	return (new_n);
}
