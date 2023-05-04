#include "main.h"

/**
 * clear_bit - bit value 0
 * @n: points to num
 * @index: bit index
 * Return: 1 otherwise -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(unsigned long int) * 8)
		return (-1);
	*n &= ~(1 << index);
	return (1);
}
