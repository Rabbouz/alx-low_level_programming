#include "lists.h"
/**
 * add_dnodeint - A function that adds a
 * new node at the beginning of a dlistint_t list
 * @head: head
 * @n: value
 * Return: the address of the new element
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new, *hd;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	hd = *head;

	if (hd != NULL)
	{
		while (hd->prev != NULL)
			hd = hd->prev;
	}

	new->next = hd;

	if (hd != NULL)
		hd->prev = new;

	*head = new;

	return (new);
}
