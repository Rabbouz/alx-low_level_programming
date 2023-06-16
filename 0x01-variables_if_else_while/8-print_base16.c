#include <stdio.h>

/**
 * main- Entry point
 *
 * Description:  printing all the numbers of base 16 in lowercase
 *
 * Return: Always 0
*/

int main(void)
{
	int i;
	char letters;

	for (i = 48; i < 58; i++)
	{
		putchar(i);
	}
	for (letters = 'a'; letters <= 'f'; letters++)
	{
		putchar(letters);
	}
	putchart('\n');
	return (0);
}
