#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - a function that initializes
 * a variable of type struct dog
 * @d: pointer
 * @name: intialized name
 * @age: initialized age
 * @owner: initialized owner
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	{
	d->name = name;
	d->age = age;
	d->owner = owner;
	}
}
