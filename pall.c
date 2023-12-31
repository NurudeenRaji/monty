#include "monty.h"

/**
 * pall - Prints the stack.
 * @stack: the stackk to print.
 * @line_number: the stack line numbers.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	(void) stack;

	if (args->head == NULL)
		return;

	temp = args->head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

