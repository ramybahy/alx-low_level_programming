#include "lists.h"

/**
 * free_listint - free a listint_t list
 * @head: pointer to the list head
 * Return: voids
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
