#include <stdio.h>

/**
 *main- Entry point
 *
 *Description: prints all single digit numbers of base 10 with putchar
 *
 *Return: Always 0
*/

int main(void)

{
	int i;

	for (i = 48; i < 59; i++)
	{
		putchar(i);
	}
	putchar('\n');
		return (0);
}
