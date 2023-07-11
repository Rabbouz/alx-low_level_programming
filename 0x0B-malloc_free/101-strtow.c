#include <stdlib.h>
#include "main.h"

/**
 * count_word - a function that  counts the number of words in a string
 * @s: string
 *
 * Return: number of words
 */

int count_word(char *s)
{
	int flag, d, x;

	flag = 0;
	x = 0;

	for (d = 0; s[d] != '\0'; d++)
	{
		if (s[d] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			x++;
		}
	}

	return (x);
}
/**
 * **strtow - a function that splits a string into words
 * @str: string to split
 *
 * Return: pointer
 * or NULL if error
 */

char **strtow(char *str)
{
	char **matrix, *tmp;
	int a, b = 0, len = 0, words, c = 0, start, end;

	while (*(str + len))
		len++;
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (a = 0; a <= len; a++)
	{
		if (str[a] == ' ' || str[a] == '\0')
		{
			if (c)
			{
				end = a;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[b] = tmp - c;
				b++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = a;
	}

	matrix[b] = NULL;

	return (matrix);
}
