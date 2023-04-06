#include "lists.h"

/**
 * print_listint - prints all  elements of  listint_t list
 * @i: pointer to the  list head
 * Return: nodes number
 */
size_t print_listint(const listint_t *i)
{
	size_t counter = 0;

	while (i)
	{
		printf("%d\n", i->n);
		i = i->next;
		counter++;
	}
	return (counter);
}
