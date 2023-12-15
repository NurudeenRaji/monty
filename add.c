#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	(void) stack;
	if (args->stack_length < 2)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
                close_file();
                free_toks();
                free_args();
                exit(EXIT_FAILURE);
        }

	node1 = args->head;
	node2 = node1->next;

	node2->n = node1->n + node2->n;
	remove_node();

	args->stack_length -= 1;
}
