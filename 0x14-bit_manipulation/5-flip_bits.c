#include "main.h"

/**
 * flip_bits - count bit number for chng
 * @n: 1st num
 * @m: 2nd num
 * Return: bit num for chng
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int spec = n ^ m;
	unsigned long int crnt;
	int j, conter = 0;

	for (j = 63; j >= 0; j--)
	{
		crnt = spec >> j;
		if (crnt & 1)
			conter++;
	}

	return (conter);
}
