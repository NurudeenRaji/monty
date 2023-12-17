#include "monty.h"

void get_entry(void);
void unknown_entry(void);
void close_file(void);
void run_entry(void);

/**
 * get_entry - Processes the functions.
 */

void get_entry(void)
{
	int i;

	instruction_t entry[] = {
		{"push", &push},
		{"pall", &pall},
		{"pint", &pint},
		{"pop", &pop},
		{"swap", &swap},
		{"add", &add},
		{"nop", &nop},
		{"sub", &sub},
		{"div", &div},
		{NULL, NULL}
	};

	if (args->n_tokens == 0)
		return;

	for (i = 0; entry[i].opcode != NULL; i++)
	{
		if (strcmp(entry[i].opcode, args->tokens[0]) == 0)
		{
			args->instruct->opcode = entry[i].opcode;
			args->instruct->f = entry[i].f;
			return;
		}
	}

	unknown_entry();
}

/**
 * unknown_entry: Clean-up error for unprocessed entry.
 */

void unknown_entry(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", args->line_num, args->tokens[0]);
	close_file();
	free_toks();
	free_args();
	exit(EXIT_FAILURE);
}

/**
 * close_file - closes the file.
 */

void close_file(void)
{
	if (args->stream == NULL)
		return;
	fclose(args->stream);
	args->stream = NULL;
}

/**
 * run_entry: executes the commands.
 */

void run_entry(void)
{
	stack_t *stack = NULL;

	if (args->n_tokens == 0)
		return;

	args->instruct->f(&stack, args->line_num);
}
