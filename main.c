#include "monty.h"

stream_s *args = NULL;

/**
 * main - Program entry point.
 * Return: 0 (Success).
 */

int main(int argc, char **argv)
{
	size_t size = 0;

	check_args(argc);
	run_args();
	get_stream(argv[1], &(args->stream));

	while (getline(&args->line, &size, args->stream) != -1)
	{
		printf("%s", args->line);
	}

	return (0);
}
