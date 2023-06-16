#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main- Entry point
 *
 * Description: print the last digit number
 *
 * Return: Always 0
*/
int main(void)
{
	int n, ldigit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	ldigit = n % 10;

	if (ldigit > 5)
		printf("Last digit of %i is %i and is greater than 5\n", n, ldigit);
	else if (ldigit == 0)
		printf("Last digit of %i is %i and is 0\n", n, ldigit);
	else if (ldigit < 6 && ldigit != 0)
		printf("Last digit of %i is %i and is less than 6 and not 0\n", n, ldigitl);

	return (0);
}
