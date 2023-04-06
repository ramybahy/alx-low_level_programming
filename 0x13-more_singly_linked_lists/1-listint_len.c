#include "lists.h"

/**
 * listint_len - returns  number of elements in  linked listint_t list
 * @i: pointer to the list head
 * Return: number of elements in a list
 */
size_t listint_len(const listint_t *i)
{
	size_t counter = 0;

	while (i)
	{
		counter++;
		i = i->next;
	}
	return (counter);
}
