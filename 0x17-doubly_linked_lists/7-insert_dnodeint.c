#include "lists.h"

/**
 * insert_dnodeint_at_index - A fucntion that
 inserts a new node at a given position
 * @h: head
 * @idx: index
 * @n: value of new node
 * Return: address of the new node, NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new;
	dlistint_t *head;
	unsigned int num;

	new = NULL;
	if (idx == 0)
		new = add_dnodeint(h, n);
	else
	{
		head = *h;
		num = 1;
		if (head != NULL)
			while (head->prev != NULL)
			head = head->prev;
		while (head != NULL)
		{
				if (num == idx)
				{
					if (head->next == NULL)
					new = add_dnodeint_end(h, n);
					else
					{
						new = malloc(sizeof(dlistint_t));
						if (new != NULL)
						{
							new->n = n;
							new->next = head->next;
							new->prev = head;
							head->next->prev = new;
							head->next = new;
						}
					}
					break;
		}
			head = head->next;
			num++;
		}
	}

	return (new);
}
