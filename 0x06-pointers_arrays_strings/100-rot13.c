#include "main.h"
#include <stdio.h>

/**
 * rot13 - Writing a function that encodes a string using rot13
 * @x: pointer to string
 *
 * Return: *x
 */

char *rot13(char *x)
{
	int a, b;

	char data1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char data2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (a = 0; x[a] != '\0'; a++)
	{
		for (b = 0; b < 52; b++)
		{
			if (x[a] == data1[b])
			{
				x[a] = data2[b];
				break;
			}
		}
	}
	return (x);
}
