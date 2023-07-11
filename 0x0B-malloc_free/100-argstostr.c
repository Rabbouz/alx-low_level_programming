#include "main.h"
#include <stdlib.h>

/**
 * argstostr - main entry
 * @ac: int
 * @av: double pointer
 * Return: 0 ALways
 */
char *argstostr(int ac, char **av)
{
	int x, z, r = 0, l = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (x = 0; x < ac; x++)
	{
		for (z = 0; av[x][z]; z++)
			l++;
	}
	l += ac;

	str = malloc(sizeof(char) * l + 1);
	if (str == NULL)
		return (NULL);
	for (x = 0; x < ac; x++)
	{
	for (z = 0; av[x][z]; z++)
	{
		str[r] = av[x][z];
		r++;
	}
	if (str[r] == '\0')
	{
		str[r++] = '\n';
	}
	}
	return (str);
}
