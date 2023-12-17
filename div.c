#include "monty.h"

/**
 * div - divides the second ekement by the top element.
 * @stack: the stack to use in division.
 * @line_number: the stack line number.
 */

void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	(void) stack;
	if(args->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		close_file();
                free_toks();
                free_args();
                exit(EXIT_FAILURE);
	}

	node1 = args->head;
	node2 = node1->next;

	if (node1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		close_file();
                free_toks();
                free_args();
                exit(EXIT_FAILURE);
	}

	node2->n = node2->n / node1->n;
	remove_node();

	args->stack_length -= 1;
}
