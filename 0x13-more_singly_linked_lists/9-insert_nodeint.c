#include "lists.h"

/**
 * insert_nodeint_at_index - insert new node at a specific position
 * @head: pointer to the list head
 * @idx: list index where the new node is added
 * @n: new node added data
 * Return: new node address, or NULL if failure
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *tmp;
	unsigned int i;

	new = malloc(sizeof(listint_t));
	if (new == NULL || head == NULL)
		return (NULL);

	new->n = n;

	/* if idx == 0, insert at the beginning */
	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	tmp = *head;
	for (i = 0; i < idx - 1; i++)
	{
		if (tmp == NULL)
		{
			free(new);
			return (NULL);
		}
		tmp = tmp->next;
	}

	new->next = tmp->next;
	tmp->next = new;

	return (new);
}
