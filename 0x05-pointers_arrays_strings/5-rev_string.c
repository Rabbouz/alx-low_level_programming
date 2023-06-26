#include "main.h"

/**
 * rev_string - Writing a function that ieverses a string
 * @s: is a string
 * Return: reversed string
 */

void rev_string(char *s)

{
	char temp = s[0];
	int len = 0;
	int x;

	while (s[len] != '\0')
	len++;
	for (x = 0; x < len; x++)
	{
		len--;
		temp = s[x];
		s[x] = s[len];
		s[len] = temp;
	}
}
