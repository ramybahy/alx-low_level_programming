#include "main.h"

/**
 * get_endianness - endianness check
 * Return: if big endian 0, if little endian 1
 */
int get_endianness(void)
{
	char *h;
	unsigned int b = 1;

	h = (char *)&b;

	return ((int)*h);
}
