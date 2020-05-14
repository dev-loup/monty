#include "monty.h"

/**
 * main - Monty command interpreter
 * Description: Monty executes file scripts with built-in code
 * @argc: argument counter
 * @argv: argument values
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	FILE *bytecode;
	char *line;
	unsigned int ln_num = 1;
	size_t len = 0;
	stack_t *h = NULL;
	stack_t *t = NULL;
	int mod = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	bytecode = fopen(argv[1], "r");

	if (bytecode == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&line, &len, bytecode)) != -1)
	{
		monty_core(line, &h, &t, &mod, ln_num);
		ln_num++;
	}

	fclose(bytecode);
	free(line);
	free_list(&h);
	return (EXIT_SUCCESS);
}
