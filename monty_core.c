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
