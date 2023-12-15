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

        args->stream = NULL;
        args->line = NULL;
}
