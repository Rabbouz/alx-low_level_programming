#include <stdio.h>

/**
 * main- Entry point
 *
 * Description: printsing the alphabet in lowercase
 *
 * Return: Always 0
*/
int main(void)
{
	char lowercase;

	for (lowercase = 'a'; lowercase <= 'z'; lowercase++)
	{
		putchar(lowercase);
	}
	putchar('\n');
		return (0);
}
