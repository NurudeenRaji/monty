#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	if (args->head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		close_file();
		free_toks();
		free_args();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", args->head->n);
}
