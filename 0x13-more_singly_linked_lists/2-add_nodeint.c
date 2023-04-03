#include "lists.h"

/**
 * add_nodeint - adds  new node at start of listint_t list
 * @head: pointer to the list head
 * @n: integer to add to a new node
 * Return: new element address, or NULL if failure
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = *head;
	*head = new;
	return (new);
}
