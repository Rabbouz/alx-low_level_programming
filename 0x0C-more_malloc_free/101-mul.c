#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"

/**
 * n_digit - A function that checks if a string contains a non-digit char
 * @s: string
 *
 * Return: 0 if a non-digit is found, 1 for else
 */
int n_digit(char *s)
{
	int x = 0;

	while (s[x])
	{
		if (s[x] < '0' || s[x] > '9')
			return (0);
		x++;
	}
	return (1);
}

/**
 * _strlen - A function that returns the length of a string
 * @s: string
 *
 * Return: lenght of string
*/

int _strlen(char *s)
{
	int x = 0;

	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}

/**
 * error - a function to handle errors for main
 */
void error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - a function to multiplies two positive numbers
 * @argc: number
 * @argv: array
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len, x, hold, digit1, digit2, *result, z = 0;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !n_digit(s1) || !n_digit(s2))
		error();
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);
	for (x = 0; x <= len1 + len2; x++)
		result[x] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = s1[len1] - '0';
		hold = 0;
		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		{
			digit2 = s2[len2] - '0';
			hold += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = hold % 10;
			hold /= 10;
		}
		if (hold > 0)
			result[len1 + len2 + 1] += hold;
	}
	for (x = 0; x < len - 1; x++)
	{
		if (result[x])
			z = 1;
		if (z)
			_putchar(result[x] + '0');
	}
	if (!z)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
