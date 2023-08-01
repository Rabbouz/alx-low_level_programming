#include "lists.h"

/**
 * add_nodeint - A function that adds a new nodee
 * at the beginning of a linked list
 * @head: pointer
 * @n: data to be inserted
 *
 * Return: a pointer, NULL if failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_n = malloc(sizeof(listint_t));

	if (!new_n)
		return (NULL);

	new_n->n = n;
	new_n->next = *head;
	*head = new_n;

	return (new_n);
}
