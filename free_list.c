#include "monty.h"

/**
 * free_list - free a stack doubly linked list
 * @head: pointer to head of the list
 * Return: voided
 */
void free_list(stack_t **head)
{
	stack_t *tmp = *head;

	if (!head)
		return;
	while (tmp->next)
	{
		tmp = tmp->next;
		free(tmp->prev);
	}
	free(tmp);
}
