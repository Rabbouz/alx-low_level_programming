#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * str_concat - a function that concatenates two strings.
 *
 *@s1: first char to be concatenated
 *@s2: second char to be concatenated
 *
 * Return: Empty string, NULL if failure
*/
char *str_concat(char *s1, char *s2)
{
	char *cnc;
	int i, c;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	i = c = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[c] != '\0')
		c++;
	cnc = malloc(sizeof(char) * (i + c + 1));

	if (cnc == NULL)
		return (NULL);
	i = c = 0;
	while (s1[i] != '\0')
	{
		cnc[i] = s1[i];
		i++;
	}

	while (s2[c] != '\0')
	{
		cnc[i] = s2[c];
		i++, c++;
	}
	cnc[i] = '\0';
	return (cnc);
}
