#include "lists.h"

/**
 * listint_len - A function that returns the number
 * of elements in a linked lists
 * @h: linked list
 *
 * Return: number of nodes(size_t)
 */

size_t listint_len(const listint_t *h)
{
	size_t number;

	number = 0;

	while (h)
	{
		number++;
		h = h->next;
	}

	return (number);
}
