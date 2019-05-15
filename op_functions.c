#include "monty.h"

/**
 * opcode_push - adds a new node at the end of a stack_t list
 * @head: pointer to the address of first linked list node
 * @n: integer to store in new node
 * Return: the address of the new element, or NULL if it failed
 */
void opcode_push(stack_t **head, char *num)
{
	stack_t *new_node;
	int n = 0;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		exit_helper(4, NULL);
	}
	n = atoi(num);
	
	if (strlen(num) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer", gl.ln);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;
	
	*head = new_node;
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
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
