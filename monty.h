#ifndef MONTY_H
#define MONTY_H

/* HEADERS */
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STRUCTURES */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct stream - the file content to check.
 * @stream: the bytecodes in the file.
 * @line: each line of the stream.
 * @line_num: the line numbers.
 * @tokens: used to tokenize.
 * @n_tokens: the number of words in the tokenized string.
 * @instruct: checks the instruction to execute.
 * @head: pointer to the head.
 * @stack_length: used to monitor the length of the stack.
 */

typedef struct stream
{
	FILE *stream;
	char *line;
	unsigned int line_num;
	char **tokens;
	int n_tokens;
	instruction_t *instruct;
	stack_t *head;
	int stack_length;
} stream_s;

/* GLOBAL VARIABLE */
extern stream_s *args;

/* FUCNTION PROTOTYPES */
void check_args(int argc);
void mem_error(void);
void run_args(void);
void close_file(void);
void get_stream(const char *filename, FILE **file);
void stream_error(const char *filename);
void tokenize(void);
void get_entry(void);
void unknown_entry(void);
void free_toks(void);
void free_args(void);
void free_head(void);
void free_stack(stack_t *head);
void run_entry(void);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
int is_num(char *s);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void remove_node(void);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);

#endif
