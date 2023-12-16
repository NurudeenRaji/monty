#include "monty.h"

void free_args(void);
void free_toks(void);
void free_head(void);
void free_stack(stack_t *head);

/**
 * free_toks - frees the token.
 */

void free_toks(void)
{
        size_t i;

        if (args->tokens == NULL)
                return;

        i = 0;
        while(args->tokens[i])
        {
                free(args->tokens[i]);
                i++;
        }
        free(args->tokens);
        args->tokens = NULL;
}

/**
 * free_args - frees the argument pointer.
 */

void free_args(void)
{
        if (args == NULL)
                return;

        if (args->instruct)
        {
                free(args->instruct);
                args->instruct = NULL;
        }
        free_head();

        if (args->line)
        {
                free(args->line);
                args->line = NULL;
        }

        free(args);
}

/**
 * free_head - frees the head.
 */

void free_head(void)
{
        if (args->head)
                free_stack(args->head);
        args->head = NULL;
}

/**
 * free_stack - frees the stack.
 * @head: pointer to the head.
 */

void free_stack(stack_t *head)
{
        if (head == NULL)
                return;
        if (head->next != NULL)
                free_stack(head->next);
        free(head);
}
