#include "monty.h"

/**
 * set_queue - sets queue or stack
 * @stack: pointer to head of stack
 * @line_number: line number
 */
void set_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	gl.qs = true;
}

/**
 * set_stack - sets to stack
 * @stack: pointer
 * @line_number: line number
 */
void set_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	gl.qs = false;
}

/**
 * opcode_queue - adds new node at end of a doubly-linked list
 * @stack: double pointer to head of list
 * @num: data for new node
 */

void opcode_queue(stack_t **stack, char *num)
{
	stack_t *current, *new = malloc(sizeof(stack_t));
	int i, n = 0;

	if (!new)
	{
		free_everything();
		exit_helper(4, NULL);
	}
	current = *stack;
	for (i = 0; num[i]; i++)
	{
		if (num[i] == '-')
			i++;
		if (num[i] < '0' || num[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", gl.ln);
			free_everything();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(num);
	if (strlen(num) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", gl.ln);
		free_everything();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	if (!*stack)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	while (current && current->next)
		current = current->next;
	if (current)
		current->next = new;
}
