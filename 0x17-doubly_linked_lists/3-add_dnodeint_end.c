#include "lists.h"
/**
 * add_dnodeint_end - A fucntion that adds a new
 * node at the end of a dlistint_t list
 * @head: head of the list
 * @n: value of the element
 * Return: address of new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *hd, *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	hd = *head;

	if (hd != NULL)
	{
		while (hd->next != NULL)
			hd = hd->next;
		hd->next = new;
	}
	else
	{
		*head = new;
	}

	new->prev = hd;

	return (new);
}
