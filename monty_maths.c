#include "monty.h"

/**
 * add - Top 2 addition
 * Description: add the top 2 numbers of the list
 * @table: access to specific data from command struct
 * Return: voided
 */

void add(cmd_t *table)
{
	stack_t **h = table->head;
	stack_t *first = NULL;
	stack_t *second = NULL;
	int sum = 0;

	if (table == NULL || h == NULL || *h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", table->line_number);
		exit(EXIT_FAILURE);
	}

	first = *h;
	second = (*h)->next;

	sum = first->n + second->n;
	second->n = sum;

	pop(table);
}

/**
 * sub - Substract the top 2 numbers
 * Description: subtracts the top 1 from the top 2 element
 * @table: access to useful variables from command struct
 * return: voided
 */

void sub(cmd_t *table)
{
	stack_t **h = table->head;
	stack_t *first = NULL;
	stack_t *second = NULL;
	int result = 0;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", table->line_number);
		exit(EXIT_FAILURE);
	}

	first = *h;
	second = (*h)->next;

	result = second->n - first->n;
	second->n = result;

	pop(table);
}

/**
 * divide - Perform division of two top stack elements
 * Description: divides top 2 with the top 1 element
 * @table: access to useful variables from command struct
 * Return: voided
 */

void divide(cmd_t *table)
{
	stack_t **h = table->head;
	stack_t *first = NULL;
	stack_t *second = NULL;
	int result;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", table->line_number);
		exit(EXIT_FAILURE);
	}

	first = *h;
	second = (*h)->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", table->line_number);
		exit(EXIT_FAILURE);
	}

	result = second->n / first->n;
	second->n = result;
	pop(table);
}

/**
 * mul - Multiply the top two elements
 * Description: multiplies the top 2 elements of the stack
 * @table: access to useful variables from command struct
 * Return: voided
 */

void mul(cmd_t *table)
{
	stack_t **h = table->head;
	stack_t *first = NULL;
	stack_t *second = NULL;
	int result;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", table->line_number);
		exit(EXIT_FAILURE);
	}

	first = *h;
	second = (*h)->next;

	result = second->n * first->n;
	second->n = result;

	pop(table);
}

/**
 * mod - Get remainder of the top elements
 * Description: Perform module operation of the second top / first top
 * @table: access to useful variables from command struct
 * Return: voided
 */

void mod(cmd_t *table)
{
	stack_t **h = table->head;
	stack_t *first = NULL;
	stack_t *second = NULL;
	int rem;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", table->line_number);
		exit(EXIT_FAILURE);
	}

	first = *h;
	second = (*h)->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", table->line_number);
		exit(EXIT_FAILURE);
	}

	rem = second->n % first->n;
	second->n = rem;

	pop(table);
}
