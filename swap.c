#include "monty.h"

/**
 * swap - swaps a node for another.
 * @stack: pointer to the stack structure.
 * @line_number: the stack line number.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	(void) stack;
	if (args->stack_length < 2)
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
                close_file();
                free_toks();
                free_args();
                exit(EXIT_FAILURE);
        }

	node1 = args->head;
	node2 = node1->next;
	node1->next = node2->next;
	if (node1->next)
		node1->next->prev = node1;

	node2->next = node1;
	node1->prev = node2;
	node2->prev = NULL;
	args->head = node2;
}
