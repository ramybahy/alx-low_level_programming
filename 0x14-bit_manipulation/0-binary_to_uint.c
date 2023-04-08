#include "main.h"

/**
 * binary_to_uint - convert bin num to unsigned int
 * @b: bin num strng
 *
 * Return:convert num
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int value = 0;
	int j;

	if (!b)
		return (0);

	for (j = 0; b[j]; j++)
	{
		if (b[j] < '0' || b[j] > '1')
			return (0);
		value = 2 * value + (b[j] - '0');
	}

	return (value);
}

