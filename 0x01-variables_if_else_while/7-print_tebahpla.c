#include <stdio.h>

/**
 *main- Entry point
 *
 *Description: printing the lowercase alphabet in reverse
 *
 *Return: Always 0
*/
int main(void)
{
	char alphabets;

	for (alphabets = 'z'; alphabets >= 'a'; alphabets--)
	{
		putchar(alphabets);
	}
	putchar('\n');
	return (0);
}
