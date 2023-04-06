#include "lists.h"

/**
 * add_nodeint - adds  new node at start of listint_t list
 * @head: pointer to the list head
 * @num: integer to add to a new node
 * Return: new element address, or NULL if failure
 */
listint_t *add_nodeint(listint_t **head, const int num)
{
	listint_t *newnode;
	newnode= malloc(sizeof(listint_t));
	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->num = num;
	newnode->next = *head;
	*head = newnode;
	return (newnode);
}
