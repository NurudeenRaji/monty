#include "monty.h"

/**
 * stream_error - prints the error messages.
 * @filename: the file  containing the bytecodes.
 */

void stream_error(const char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	free(args);
	exit(EXIT_FAILURE);
}

/**
 * get_stream - opens the file.
 * @filename: the file containing the bytecodes.
 * @file: pointer to the struct.
 */

void get_stream(const char *filename, FILE **file)
{
	*file = fopen(filename, "r");
	if (*file == NULL)
	{
		stream_error(filename);
	}
}
