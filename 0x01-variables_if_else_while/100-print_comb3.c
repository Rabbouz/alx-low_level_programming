#include <stdio.h>

/**
 *main- Entry point
 *
 * Description: prints all possible different
 * combinations of two digits using putchar
 *
 * Return: Always 0
*/

int main(void)
{
	int i, s;

	for (i = 48; i < 58; i++)
	{
		for (s = 48; s < 58; s++)
		{
			if (i < s)
			{
				putchar(i);
				putchar(s);
				if (i != 56 || s != 57)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
