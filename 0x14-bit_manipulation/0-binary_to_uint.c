#include "main.h"

/**
 * binary_to_uint - convert a bin num to an unsigned int
 * b:  bin num string
 *
 * Return: num converted
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int value = 0;

	if (!b)
		return (0);

	for (i = 0; b[j]; j++)
	{
		if (b[j] < '0' || b[j] > '1')
			return (0);
		value = 2 * value + (b[j] - '0');
	}

	return (value);
}

