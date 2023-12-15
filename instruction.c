#include "monty.h"

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

void unknown_entry(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", args->line_num, args->tokens[0]);
	close_file();
	free_toks();
	free_args();
	exit(EXIT_FAILURE);
}


void close_file(void)
{
	if (args->stream == NULL)
		return;
	fclose(args->stream);
	args->stream = NULL;
}

void run_entry(void)
{
	stack_t *stack = NULL;

	if (args->n_tokens == 0)
		return;

	args->instruct->f(&stack, args->line_num);
}
