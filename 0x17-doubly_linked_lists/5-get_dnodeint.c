#include "lists.h"

/**
 * sum_dlistint - A function that returns
 * the sum of all the data (n) of a doubly linked list
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
