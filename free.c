#include "monty.h"

/**
 * free_dlistint - frees a doubly-linked list
 * @head: pointer to head of list
 * Return: void
 */

void free_dlistint(stack_t *head)
{
	stack_t *next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

/**
 * free_everything - frees everything
 */
void free_everything(void)
{
	free(gl.line);
	free_dlistint(gl.stack);
	fclose(gl.monty);
}
