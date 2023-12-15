#include "monty.h"

void pop(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	if (args->head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		close_file();
		free_toks();
		free_args();
		exit(EXIT_FAILURE);
	}

	remove_node();
	args->stack_length -= 1;
}

void remove_node(void)
{
	stack_t *temp;

	temp = args->head;
	args->head = temp->next;
	free(temp);
}
