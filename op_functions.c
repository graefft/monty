#include "monty.h"

/**
 * opcode_push - adds a new node at the end of a stack_t list
 * @head: pointer to the address of first linked list node
 * @num: pointer to second argument of opcode
 * Return: nothing
 */
void *opcode_push(stack_t **head, char *num)
{
	stack_t *new_node;
	stack_t *last;
	int n;
	int i;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	while (num)
	{
		if (!isdigit(num[i]))
		{
			fprintf(stderr, "L%d: usage: push integer", gl.ln);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (strlen(num) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer", gl.ln);
		exit(EXIT_FAILURE);
	}
	n = atoi(num);

	new_node->n = n;
	last = (*head);
	new_node->next = NULL;

	if (*head == NULL)
	{
		(*head) = NULL;
		(*head) = new_node;
	}

	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}

/**
 * opcode_pall - prints all the elements of a stack_t list
 * @stack: pointer to the address of node in stack_t list
 * @line_number: line number of opcode
 * Return: nothing
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	const stack_t *temp;

	temp = (*stack);
	while (temp != NULL)
	{
		temp = temp->next;
		printf("%d\n", temp->n);
	}
}
