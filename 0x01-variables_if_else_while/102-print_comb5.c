#include <stdio.h>

/**
 * main- Entry point
 *
 * Description: printing all possible combinations of two two-digit numbers
 * using putchar,loops,conditions*
 * Return: Always 0
*/

int main(void)
{
	int i, a;

	for (i = 0; i < 100; i++)
	{
		for (a = 0; a < 100; a++)
		{
		if (i < a)
		{
			putchar((i / 10) + 48);
			putchar((i % 10) + 48);
			putchar(' ');
			putchar((a / 10) + 48);
			putchar((a % 10) + 48);
			if (i != 98 || a != 99)
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
