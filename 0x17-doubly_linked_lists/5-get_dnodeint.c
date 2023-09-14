#include "lists.h"

/**
 * get_dnodeint_at_index - A function that print the nth node of
 * a dlistint_t linked list.
 * @head: head
 * @index: index
 * Return: sum
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned sum = 0;

	if (head == NULL)
	return (0);

	while (head != NULL)
	{
		if (sum == index)
		{
			if (head != NULL)
			return (head);
			else
			return (NULL);
		}
			head = head->next;
			sum++;
	}
	return (head);
}
