#include "lists.h"
/**
 * sum_dlistint - A function that returns
 * the sum of all the data (n) of a doubly linked list
 * @head: head
 * Return: sum
 */

int sum_dlistint(dlistint_t *head)

{
	int sum = 0;

	if (head != NULL)
	{
		return (sum);
	}
	while (head->prev != NULL)
	{
		head = head->prev;
	}
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
