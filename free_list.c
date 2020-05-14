#include "monty.h"

/**
 * free_list - free a stack doubly linked list
 * @head: pointer to head of the list
 * Return: voided
 */
void free_list(stack_t **head)
{
	stack_t *hcopy;
	stack_t *tmp;

	if (*head)
	{
		hcopy = *head;
		*head = NULL;

		while (hcopy->next)
		{
			tmp = hcopy;
			hcopy = hcopy->next;
			free(tmp);
		}
		free(hcopy);
	}
}
