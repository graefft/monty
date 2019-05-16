#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct dlist_s - global struct
 * @line: line that is read
 * @monty: file to be read from
 * @read: read line
 * @ln: line number
 * @stack: stack
 */
typedef struct dlist_s
{
	char *line;
	char **read;
	FILE *monty;
	stack_t *stack;
	unsigned int ln;
} dlist_t;

extern dlist_t gl;

int get_op(stack_t **stack, char *which);
void opcode_push(stack_t **head, char *num);
void opcode_pall(stack_t **stack, unsigned int line_number);

void exit_helper(int code, char *file);
void free_dlistint(stack_t *head);
void free_stack(stack_t *stack);
void free_everything();
#endif /* MONTY_H */
