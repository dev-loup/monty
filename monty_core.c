#include "monty.h"

/**
 * monty_core - pack arguments for functions and execute
 * @line: line of input to parse
 * @h: head of doubly linked list
 * @t: tail of doubly linked list
 * @md: stack or queue mode
 * @ln: line number being evaluated
 */
void monty_core(char *line, stack_t **h, stack_t **t, int *md, unsigned int ln)
{
	cmd_t table;
	int chk_code;

	table.mode = md;
	table.line_number = ln;
	table.head = h;
	table.tail = t;
	chk_code = tok_validator(line, &table);
	if (chk_code == 1)
		m_executer(&table);
}
/**
 * stack - change the mode to stack
 * description: set the mode to stack
 * @table: container of arguments
 * Return: voided
 */

void stack(cmd_t *table)
{
	*table->mode = 0;
}

/**
 * queue - change to mode of the stack
 * Description: set the stack to queue mode
 * @table: Arguments of functions
 * Return: voided
 */

void queue(cmd_t *table)
{
*table->mode = 1;
}