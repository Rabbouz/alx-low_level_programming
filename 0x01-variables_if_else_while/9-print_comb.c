#include <stdio.h>

/**
 * main- Entry Point
 *
 * Description: printing all possible combinations of single-digit numbers
 * usibg putchar
 *
 * Return: Always 0
*/

int main(void)
{
	int i;

	for (i = 48; i <= 58; i++)
{
	putchar(i);
	putchar(',');
	putchar(' ');
}
putchar('\n');
return (0);
}
