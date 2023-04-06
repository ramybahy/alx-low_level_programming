#include "lists.h"

/**
 * get_nodeint_at_index - return nth node of listint_t linked list
 * @head: pointer to the list head
 * @index: node index, starting at 0
 * Return: nth node of  listint_t linked list, or NULL if node do
 * not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int j;

	for (j = 0; j < index && head; j++)
		head = head->next;

	return (head);
}
