#include "lists.h"

/**
 * pop_listint - delete head node of  listint_t linked list, return
 * node head data (n)
 * @head: pointer to the list head
 * Return:  node head data (n), or 0 if empty list
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (*head == NULL)
		return (0);
	temp = *head;
	n = temp->n;
	*head = (*head)->next;
	free(temp);
	return (n);
}

