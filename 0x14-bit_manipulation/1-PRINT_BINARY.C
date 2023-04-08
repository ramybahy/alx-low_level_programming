#include "main.h"

/**
 * print_binary - print bin eq of  dec num
 *@n: num print in bin
 */
void print_binary(unsigned long int n)
{
	unsigned long int crnt;
	int j, conter = 0;

	for (j = 63; j >= 0; j--)
	{
		crnt = n >> j;

		if (crnt & 1)
		{
			_putchar('1');
			conter++;
		}
		else if (conter)
			_putchar('0');
	}
	if (!conter)
		_putchar('0');
}

