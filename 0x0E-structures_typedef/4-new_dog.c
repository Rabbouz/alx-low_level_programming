#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - a function that returns the length of a string
 * @st: string
 *
 * Return: length
 */
int _strlen(char *st)
{
	int lnt = 0;

	while (*st++)
	{
		lnt++;
	}

	return (lnt);
}

/**
 * *_strcpy - a functioin that copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest.
 * @dest: pointer
 * @src: copied string
 *
 * Return: pointer
 */

char *_strcpy(char *dest, char *src)
{
	int lent, x;

	lent = 0;

	while (src[lent] != '\0')
	{
		lent++;
	}

	for (x = 0; x < lent; x++)
	{
		dest[x] = src[x];
	}
	dest[x] = '\0';

	return (dest);
}

/**
 * new_dog - creating a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return:a  pointer, NULL otherwise
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int lent1, lent2;

	lent1 = _strlen(name);
	lent2 = _strlen(owner);

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc(sizeof(char) * (lent1 + 1));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	dog->owner = malloc(sizeof(char) * (lent2 + 1));
	if (dog->owner == NULL)
	{
		free(dog);
		free(dog->name);
		return (NULL);
	}
	_strcpy(dog->name, name);
	_strcpy(dog->owner, owner);
	dog->age = age;

	return (dog);
}
