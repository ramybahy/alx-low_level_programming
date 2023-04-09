#include "main.h"

/**
 * set_bit - start prog
 * @n: evaluate 1st int
 * @index: evaluate 2nd int
 * Description: set  bit value to 1
 * Return: return req func sig. (0)
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}
	*n ^= (1 << index);
	return (1);
}
