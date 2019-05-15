#include "monty.h"

/**
 * opcode_push - adds a new node at the end of a stack_t list
 * @head: pointer to the address of first linked list node
 * @n: integer to store in new node
 * Return: the address of the new element, or NULL if it failed
 */
void *opcode_push(stack_t **head, char *n)
{
	stack_t *new_node;
	stack_t *last;
	const int num;
	int i;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	while (n)
	{
		if (!isdigit(n[i]))
		{
			fprintf(stderr, "L%d: usage: push integer", gl.ln);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (strlen(n) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer", gl.ln);
		exit(EXIT_FAILURE);
	}
	num = atoi(n);

	new_node->num = num;
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
 * @h: pointer to first node in linked list
 * Return: the number of nodes
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
