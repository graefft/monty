#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
 * @qs: queue / stack flag
 * @line: line that is read
 * @monty: file to be read from
 * @read: read line
 * @ln: line number
 * @stack: stack
 */
typedef struct dlist_s
{
	_Bool qs;
	char *line;
	char **read;
	FILE *monty;
	stack_t *stack;
	unsigned int ln;
} dlist_t;

extern dlist_t gl;

/* op_1.c */
void opcode_push(stack_t **head, char *num);
void opcode_pall(stack_t **stack, unsigned int line_number);
void opcode_pint(stack_t **stack, unsigned int line_number);
void opcode_pop(stack_t **stack, unsigned int line_number);
void opcode_swap(stack_t **stack, unsigned int line_number);

/* op_2.c */
void opcode_add(stack_t **stack, unsigned int line_number);
void opcode_nop(stack_t **stack, unsigned int line_number);
void opcode_sub(stack_t **stack, unsigned int line_number);
void opcode_mul(stack_t **stack, unsigned int line_number);
void opcode_div(stack_t **stack, unsigned int line_number);

/* op_3.c */
void opcode_mod(stack_t **stack, unsigned int line_number);
void opcode_pchar(stack_t **stack, unsigned int line_number);
void opcode_pstr(stack_t **stack, unsigned int line_number);
void opcode_rotl(stack_t **stack, unsigned int line_number);
void opcode_rotr(stack_t **stack, unsigned int line_number);

/* queue.c */
void opcode_queue(stack_t **stack, char *num);
void set_stack(stack_t **stack, unsigned int line_number);
void set_queue(stack_t **stack, unsigned int line_number);

/* main.c */
int get_op(stack_t **stack, char *which);
void initialize(void);
void exit_helper(int code, char *file);

/* free.c */
void free_dlistint(stack_t *head);
void free_stack(stack_t *stack);
void free_everything(void);

#endif /* MONTY_H */
