#include "lists.h"

/**
 * sum_listint - return sum of all data (n) of listint_t linked list
 * @head: pointer to the list head
 * Return: sum of all data (n) of listint_t linked list
 */
int sum_listint(listint_t *head)
{
	int sum;

	for (sum = 0; head; head = head->next)
		sum += head->n;

	return (sum);
}

