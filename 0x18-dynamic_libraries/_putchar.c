#include <unistd.h>

/**
 * _putchar - write chartr c for stdout
 * @c: print char
 *
 * Return: 1 as success
 * if error, return -1
 */
int _putchar(char c)
{
       return (write(1, &c, 1));
}
