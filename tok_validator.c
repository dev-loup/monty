#include "monty.h"

/**
 * tok_validator - get and validate tokens
 * @line: line to check
 * @table: command table
 * Return: 0 if command is mode set or not valid & 1 approves
 */
int tok_validator(char *line, cmd_t *table)
{
	char delims[] = " \t\r\n", *opcode, *arg;
	int len;
	unsigned int ln = table->line_number;

	if (line == NULL)
		return (0);
	opcode = strtok(line, delims);
	if (opcode == NULL || opcode[0] == '#')
		return (0);
	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, delims);
		if (arg == NULL)
		{
			printf("L%d: usage: push integer\n", ln);
			free(line);
			free_list(table->head);
			fclose(bytecode);
			exit(EXIT_FAILURE);
		}
		for (len = (strlen(arg) - 1); len >= 0; len--)
		{
			if (len == 0 && arg[len] == '-')
				break;
			if (arg[len] > 57 || arg[len] < 48)
			{
				printf("L%d: usage: push integer\n", ln);
				free(line);
				free_list(table->head);
				fclose(bytecode);
				exit(EXIT_FAILURE);
			}
		}
		table->arg = atoi(arg);
		table->opcode = opcode;
		return (1);
	}
	table->opcode = opcode;
	return (1);
}
