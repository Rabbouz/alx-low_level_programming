#include <stdlib.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list
 * @h: pointer
 *
 * Return: number of h
 */
size_t list_len(const list_t *h)
{
	size_t x;

	x = 0;

	while (h)
	{
		x++;
		h = h->next;
	}
	return (x);
}
