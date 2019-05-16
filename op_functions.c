#include "monty.h"

/**
 * opcode_push - adds a new node at the end of a stack_t list
 * @head: pointer to the address of first node in a linked list
 * @num: pointer to second argument in a line number
 * Return: nothing
 */
void opcode_push(stack_t **head, char *num)
{
	stack_t *new_node;
	int n = 0;
	int i;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free_everything();
		exit_helper(4, NULL);
	}

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
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	n = atoi(num);

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;
}

/**
 * opcode_pall - prints all the elements of a stack_t list
 * @stack: pointer to the address of node in stack_t list
 * @line_number: line number in the file
 * Return: nothing
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	const stack_t *temp;

	(void)line_number;
	temp = (*stack);
	while (temp != temp->prev)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * opcode_pint - prints the value at the top of the stack
 * @stack: pointer to the address of node in stack_t list
 * @line_number: line number in the file
 * Return: nothing
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", gl.ln);
		free_everything();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
	(*stack) = NULL;
}

/**
 * opcode_nop - does not perform the instruction
 * @stack: pointer to the address of node in stack_t list
 * @line_number: line number in the file
 * Return: nothing
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
