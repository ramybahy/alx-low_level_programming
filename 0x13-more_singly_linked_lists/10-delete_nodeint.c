#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at  index of a
 * listint_t linked list
 * @head: double pointer to the list head
 * @index:  node index that should be deleted. Index starts at 0
 * Return: 1 if  success, -1 if failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int j;
	listint_t *tmp1, *tmp2;

	if (head == NULL || *head == NULL)
		return (-1);

	/* if index == 0, delete head */
	if (index == 0)
	{
		tmp1 = *head;
		*head = (*head)->next;
		free(tmp1);
		return (1);
	}

	tmp1 = *head;
	for (j = 0; j < index - 1; j++)
	{
		if (tmp1 == NULL)
			return (-1);
		tmp1 = tmp1->next;
	}

	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	free(tmp2);

	return (1);
}

