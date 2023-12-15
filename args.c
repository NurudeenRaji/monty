#include "monty.h"

void check_args(int argc)
{
        if (argc ==  2)
                return;
        
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

void mem_error(void)
{
        fprintf(stderr, "malloc failed!\n");
        free(args);
        exit(EXIT_FAILURE);
}

void run_args(void)
{
        args = malloc(sizeof(stream_s));
        if (args == NULL)
                mem_error();

	args->instruct = malloc(sizeof(instruction_t));
	if (args->instruct == NULL)
		mem_error();

        args->stream = NULL;
        args->line = NULL;
	args->head = NULL;
	args->tokens = NULL;
	args->stack_length = 0;
	args->n_tokens = 0;
	args->line_num = 0;
}
