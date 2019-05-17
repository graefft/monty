#include "monty.h"

/**
 * opcode_mod - computes the rest of the division of top two elements of stack
 * @stack: pointer to address of stack
 * @line_number: line number
 * Return: void
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
        stack_t *current = *stack;
        int result = 0;

        (void)line_number;
        if (current == NULL || current->next == NULL)
        {
                fprintf(stderr, "L%u: can't mod, stack too short\n", gl\
			.ln);
                free_everything();
                exit(EXIT_FAILURE);
        }

        if (current->n == 0)
        {
                fprintf(stderr, "L%u: division by zero\n", gl.ln);
                free_everything();
                exit(EXIT_FAILURE);
        }

        result = current->next->n % current->n;
        current->next->n = result;
        *stack = current->next;
        free(current);
        (*stack)->prev = NULL;
}
