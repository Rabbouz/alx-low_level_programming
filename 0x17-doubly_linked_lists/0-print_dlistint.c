#include "lists.h"

/**
 * print_dlistint - A function that
 * prints all the elements of a dlistint_t list
 * @hd: head
 * Return: number of nodes
 */

size_t print_dlistint(const dlistint_t *hd)
{
	int counter;

	counter = 0;

	if (hd == NULL)
		return (counter);

	while (hd->prev != NULL)
		hd = hd->prev;

	while (hd != NULL)
	{
		printf("%d\n", hd->n);
		counter++;
		hd = hd->next;
	}

	return (counter);
}
