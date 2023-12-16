#include "monty.h"

void push(stack_t **stack, unsigned int line_number);
int is_num(char *s);

/**
 * push - Add a node to the stack.
 * @stack: Pointer to the stack itself.
 * @line_number: The line number to add the node.
 */

void push(stack_t **stack, unsigned int line_number)
{
	if (args->n_tokens <= 1 || !(is_num(args->tokens[1])))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_args();
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		mem_error();
	}

	(*stack)->next = (*stack)->prev = NULL;

	(*stack)->n = (int) atoi(args->tokens[1]);

	if (args->head != NULL)
	{
		(*stack)->next = args->head;
		args->head->prev = *stack;
	}
	args->head = *stack;
	args->stack_length += 1;
}

/*
 * is_num - check the entry if it's a number.
 * @s: the string to check.
 * Return: 1(Success).
 */

int is_num(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] == '-' && s[i + 1])
		{
			i++;
			continue;
		}
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}

	return (1);
}
