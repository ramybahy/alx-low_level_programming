#include "lists.h"

/**
 * free_listint_safe - free listint_t list
 * @h: double pointer to the list head
 * Return: list size that is freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t i;
	listint_t *tmp, *tmp2;

	if (h == NULL || *h == NULL)
		return (0);

	for (i = 0; *h; i++)
	{
		tmp = *h;
		*h = (*h)->next;
		free(tmp);
		tmp2 = *h;
		while (tmp2)
		{
			if (tmp2 <= tmp)
			{
				*h = NULL;
				break;
			}
			tmp2 = tmp2->next;
		}
	}

	return (i);
}

