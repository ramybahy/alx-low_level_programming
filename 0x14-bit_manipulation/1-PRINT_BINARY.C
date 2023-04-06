#include "main.h"

/**
 * print_binary - print bin eq of  dec num
 * n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int j, cnt = 0;
	unsigned long int current;

	for (j = 63; j >= 0; j--)
	{
		cur = n >> i;

		if (cur & 1)
		{
			_putchar('1');
			cnt++;
		}
		else if (cnt)
			_putchar('0');
	}
	if (!cnt)
		_putchar('0');
}

