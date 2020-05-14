#include "monty.h"

/**
 * pall - print the stack
 * description: in assigned mode pall print the stack stored
 * @table: argument container for functions
 * Return: voided
 */

void pall(cmd_t *table)
{
	stack_t *h = *table->head;

	if (h == NULL)
		return;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * Description: prints the top value of the stack
 * @table: access to specific data from command struct
 * Return: voided
 */

void pint(cmd_t *table)
{
	stack_t *h = *table->head;

	if (h == NULL)
	{
		printf("L%d: can't pint, stack empty\n", table->line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", h->n);
}

/**
 * pchar - prints ASCII char
 * description: prints the top stack as an ASCII char
 * @table: argument container for functions
 * Return: voided
 */

void pchar(cmd_t *table)
{
	stack_t *h = *table->head;

	if (h == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", table->line_number);
		exit(EXIT_FAILURE);
	}

	if (h->n < 0 || h->n > 127)
	{
		printf("L%d: can't pchar, value out of range\n", table->
		       line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", h->n);
}

/**
 * pstr - prints a satack as ASCII characters
 * Description: converts numbers to ASCII and prints a string
 * @table: argument container for functions
 * Return: voided
 */

void pstr(cmd_t *table)
{
	stack_t *h = *table->head;

	if (h == NULL)
	{
		putchar('\n');
		return;
	}

	while (h != NULL && (h->n > 0 && h->n <= 127))
	{
		printf("%c", h->n);
		h = h->next;
	}
	putchar('\n');
}

/**
 * nop - undetermined existance
 * Description: nop does nothing known
 * @table: argument container for functions
 * Return: voided
 */

void nop(cmd_t *table)
{
	(void)table;
}
