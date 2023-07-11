#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicatng to new memory space location
 * @str: char
 * Return: 0
 */

char *_strdup(char *str)
{

	char *ch;
	int i, b = 0;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	ch = malloc(sizeof(char) * (i + 1));

	if (ch == NULL)
		return (NULL);

	for (b = 0; str[b]; b++)
		ch[b] = str[b];

	return (ch);
}
