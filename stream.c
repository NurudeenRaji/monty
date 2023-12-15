#include "monty.h"

void stream_error(const char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	free(args);
	exit(EXIT_FAILURE);
}

void get_stream(const char *filename, FILE **file)
{
	*file = fopen(filename, "r");
	if (*file == NULL)
	{
		stream_error(filename);
	}
}
