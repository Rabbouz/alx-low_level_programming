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
	int n, lastDigital;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastDigital = n % 10;

	if (lastDigital > 5)
		printf("Last digit of %d is %d and is greater than 5\n", lastDigital);
	else if (lastDigital == 0)
		printf("Last digit of %d is %d and is 0\n", lastDigital);
	else if (lastDigital < 6 && lastDigital != 0)
		printf("Last digit of %d is %d and is less than 6 and not 0\n", lastDigital);

	return (0);
}
