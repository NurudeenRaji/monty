#include "monty.h"

void tokenize(void)
{
	int i = 0;
	char *token = NULL;
	char *line_copy = NULL;

	line_copy = malloc(sizeof(char) * (strlen(args->line) + 1));
	strcpy(line_copy, args->line);
	args->n_tokens = 0;
	token = strtok(line_copy, " \n");
	while (token)
	{
		args->n_tokens += 1;
		token = strtok(NULL, " \n");
	}

	args->tokens =  malloc(sizeof(char *) * (args->n_tokens + 1));
	strcpy(line_copy, args->line);
	token = strtok(line_copy, " \n");
	while(token)
	{
		args->tokens[i] = malloc(sizeof(char)  * (strlen(token) + 1));
		if (args->tokens[i] == NULL)
			mem_error();
		strcpy(args->tokens[i], token);
		token = strtok(NULL, " \n");
		i++;
	}

	args->tokens[i] = NULL;
	free(line_copy);
}
