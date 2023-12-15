#include "monty.h"

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

void free_head(void)
{
        if (args->head)
                free_stack(args->head);
        args->head = NULL;
}

void free_stack(stack_t *head)
{
        if (head == NULL)
                return;
        if (head->next != NULL)
                free_stack(head->next);
        free(head);
}
