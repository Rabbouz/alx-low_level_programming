#include <stdio.h>

/**
 * main- Entry point
 *
 * Description: printing all possible different combinations
 * of three digits using putchar, loop, conditions
 *
 * Return: Always 0
*/

int main(void)

{
	int i, d, c;

	for (i = 48; i < 58; i++)
	{
		for (d = 48; d < 58; d++)
		{
			for (c = 48; c < 58; c++)
			{
				if (c > d && d > i)
				{
					putchar(i);
					putchar(d);
					putchar(c);
					if (i != 55 || d != 56)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
putchar('\n');
return (0);
}
