#include "lists.h"

/**
 * print_listint - prints all  elements of  listint_t list
 * @h: pointer to the  list head
 * Return: nodes number
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
}
