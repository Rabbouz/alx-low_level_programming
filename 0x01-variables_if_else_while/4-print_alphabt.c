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
	char letters;

	for (letters = 'a'; letters <= 'z'; letters++)
	{
		if (letters == 'e' || letters == 'q')
			continue;
	putchar(letters);
	}
	putchar('\n')
		return (0);


}
