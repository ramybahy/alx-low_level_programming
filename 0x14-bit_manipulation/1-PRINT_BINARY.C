#include "main.h"

/**
 * print_binary - print bin eq of  dec num
 * n: num print in bin
 */
void print_binary(unsigned long int n)
{
	int j, counter = 0;
	unsigned long int crnt;

	for (j = 63; j >= 0; j--)
	{
		crnt = n >> j;

		if (crnt & 1)
		{
			_putchar('1');
			crnt++;
		}
		else if (counter)
			_putchar('0');
	}
	if (!counter)
		_putchar('0');
}

