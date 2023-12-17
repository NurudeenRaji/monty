#include "monty.h"

/**
 * pop - removes the node at the top of the stack.
 * @stack: pointerb to the stack structure.
 * @line_number: the stack line number.
 */

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

/**
 * remove_node - performs the pop.
 */

void remove_node(void)
{
	stack_t *temp;

	temp = args->head;
	args->head = temp->next;
	free(temp);
}
