#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - A function that frees dogs =)
 * @d: struct dog(pinter) to free
 *
 *Return: void
 */

void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
