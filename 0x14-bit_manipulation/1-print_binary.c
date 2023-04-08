#include "main.h"

/**
 * print_binary - print bin eq to dec num
 * @n: num print in bin
 */
void print_binary(unsigned long int n)
{
	unsigned long int curnt;
	int j, contr = 0;

	for (j = 63; j >= 0; j--)
	{
		curnt = n >> j;

		if (curnt & 1)
		{
			_putchar('1');
			contr++;
		}
		else if (contr)
			_putchar('0');
	}
	if (!contr)
		_putchar('0');
}

