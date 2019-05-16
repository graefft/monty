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
	while (temp != NULL)
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
	const stack_t *temp;

	(void)line_number;
	temp = (*stack);
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", gl.ln);
		free_everything();
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", temp->n);
}

/**
 * opcode_pop - removes the top element of the stack
 * @stack: pointer to address of node in stack_t list
 * @line_number: line number in file
 * Return: void
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *current = *stack;

	(void)line_number;
	if (current == NULL)
		exit_helper(7, NULL);

	temp = current->next;
	free(current);
	*stack = temp;
	current = *stack;
	if (current)
		current->prev = NULL;
}

/**
 * opcode_swap - swaps the top two elements of the stack
 * @stack: pointer to the address of node in stack_t list
 * @line_number: line number in the file
 * Return: nothing
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *current = *stack;
	int x;

	(void)line_number;
	if (current->next == NULL || current == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", gl.ln);
		free_everything();
		exit(EXIT_FAILURE);
	}
	temp->n = current->n;
	x = current->next->n;
	current->next->n = temp->n;
	current->n = x;

}
