#include "monty.h"

/**
 * m_executer - execute opcode functions
 * description: m_executer takes argument table to execute code
 * @table: data to pass to function
 * Return: voided
 */
void m_executer(cmd_t *table)
{
	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i = 0;

	while (funcs[i].opcode)
	{
		if (strcmp(table->opcode, funcs[i].opcode) == 0)
		{
			funcs[i].f(table);
			return;
		}
		i++;
	}

	printf("L%d: unknown instruction %s\n", table->line_number, table->opcode);
	free_list(table->head);
	exit(EXIT_FAILURE);
}
