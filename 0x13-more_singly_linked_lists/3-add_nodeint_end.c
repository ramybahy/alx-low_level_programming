#include "lists.h"

/**
 * add_nodeint_end - adds  new node at  end of listint_t list
 * @head: pointer to the list head
 * @n: integer to add to new node
 * Return: new element address, or NULL if failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *last;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;
	return (new);
}
