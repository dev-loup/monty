#include "monty.h"

/**
 * push - adds a new node
 * Description: adds a node in stack or queue mode
 * @table: argument container for functions
 * Return: new node or EXIT_FAILURE
 */

void push(cmd_t *table)
{
	stack_t **h = table->head, *new = NULL, *temp = NULL;

	if (h == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", table->line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);
	if (*table->mode == 1)
	{
		new->n = table->arg;
		new->next = NULL;
		new->prev = NULL;
		if (*h == NULL)
		{
			*h = new;
			return;
		}
		temp = *h;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
		return;
	}
	if (*h == NULL)
	{
		new->n = table->arg;
		new->next = *h;
		new->prev = NULL;
		*h = new;
		return;
	}
	(*h)->prev = new;
	new->n = table->arg;
	new->next = *h;
	new->prev = NULL;
	*h = new;
}

/**
 * pop - removes top element
 * Description: removes the top 1 element of the stack
 * @table: argument container for functions
 * Return: voided
 */

void pop(cmd_t *table)
{
	stack_t **h = table->head;
	stack_t *tmp = NULL;

	if (*h == NULL || h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", table->line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *h;
	*h = (*h)->next;
	free(tmp);
}

/**
 * swap - swaps the top two elements
 * Description: Swaps the top nodes of the stack
 * @table: argument container for functions
 * Return: voided
 */

void swap(cmd_t *table)
{
	stack_t **h = table->head;
	stack_t *first = NULL;
	stack_t *second = NULL;
	stack_t *third = NULL;

	if (*h == NULL || h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", table->line_number);
		exit(EXIT_FAILURE);
	}
	first = *h;
	second = (*h)->next;
	third = second->next;

	first->next = second->next;
	second->next = first;
	if (third)
		third->prev = first;
	first->prev = second;
	second->prev = NULL;
	*h = second;
}

/**
 * rotl - Stack reversion
 * Description: Reverse all the data from stack to queue
 * @table: argument container for functions
 * Return: voided
 */

void rotl(cmd_t *table)
{
	stack_t **h = table->head;
	stack_t *first = NULL;
	stack_t *second = NULL;
	stack_t *last = NULL;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
		return;

	if ((*h)->next->next == NULL)
	{
		swap(table);
		return;
	}

	first = *h;
	second = (*h)->next;
	last = *h;

	while (last->next != NULL)
		last = last->next;

	first->next = last->next;
	first->prev = last;
	last->next = first;
	second->prev = NULL;
	*h = second;
}

/**
 * rotr - Queue reversion
 * Description: performs a queue reversion to stack
 * @table: argument container for functions
 */

void rotr(cmd_t *table)
{
	stack_t **h = table->head;
	stack_t *first = NULL;
	stack_t *second = NULL;
	stack_t *last = NULL;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
		return;

	if ((*h)->next->next == NULL)
	{
		swap(table);
		return;
	}

	first = *h;
	second = *h;
	last = *h;

	while (last->next != NULL)
		last = last->next;

	while (second->next != last)
		second = second->next;

	last->next = first;
	last->prev = first->prev;
	first->prev = last;
	second->next = NULL;
	*h = last;
}
