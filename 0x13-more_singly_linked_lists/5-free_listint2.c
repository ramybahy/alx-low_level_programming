#include "lists.h"

/**
 * free_listint2 - free a listint_t list
 * @head: pointer to the list head
 * Return: voids
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;
	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*head = NULL;
}
