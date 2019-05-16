#include "monty.h"

dlist_t gl;

/**
 * main - entry point for Monty interpretor
 * @argc: number of arguments
 * @argv: opcode arguments
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *which, *push_op, *delim = " \t\r\n";
	int get, find = 0;
	size_t bufsize = 0;

	initialize();
	if (argc != 2)
		exit_helper(1, NULL);
	gl.monty = fopen(argv[1], "r");
	if (gl.monty == NULL)
		exit_helper(2, argv[1]);

	while ((get = getline(&gl.line, &bufsize, gl.monty)) != EOF)
	{
		gl.ln++;
		which = strtok(gl.line, delim);
		if (which == NULL || *which == '#')
		{
			continue;
		}
		if (strcmp(which, "push") == 0)
		{
			push_op = strtok(NULL, delim);
			if (!push_op)
			{
				free_everything();
				exit_helper(5, NULL);
			}
			opcode_push(&gl.stack, push_op);
			continue;
		}
		find = get_op(&gl.stack, which);
		if (find < 0)
		{
			exit_helper(3, gl.line);
		}
	}
	free_everything();
	return (EXIT_SUCCESS);
}

/**
 * get_op - selects correct function to perform operation
 * @stack: stack
 * @which: parsed input
 * Return: pointer to function corresponding to operator
 */
int get_op(stack_t **stack, char *which)
{
	char *op;
	int i = 0;
	instruction_t ops[] = {
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"add", opcode_add},
		{"nop", opcode_nop},
		{NULL, NULL}
		};

	op = strtok(which, " ");

	while (ops[i].opcode)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, gl.ln);
			return (0);
		}
		i++;
	}
	return (-1);
}

/**
 * exit_helper - exit handler for monty program
 * @code: error number
 * @file: input
 */
void exit_helper(int code, char *file)
{
	switch (code)
	{
		case 1:
		{
			fprintf(stderr, "USAGE: monty file\n");
			break;
		}
		case 2:
		{
			fprintf(stderr, "Error: Can't open file %s\n", file);
			break;
		}
		case 3:
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", gl.ln, file);
			free_everything();
			break;
		}
		case 4:
		{
			fprintf(stderr, "Error: malloc failed\n");
			break;
		}
		case 5:
		{
			fprintf(stderr, "L%u: usage: push integer\n", gl.ln);
			break;
		}
		case 6:
		{
			fprintf(stderr, "L%u: can't pint, stack empty\n", gl.ln);
			break;
		}
		case 7:
		{
			fprintf(stderr, "L%d: can't pop an empty stack\n", gl.ln);
			break;
		}
	}
	exit(EXIT_FAILURE);
}

/**
 * initialize - initializes struct
 */
void initialize(void)
{
	gl.monty = NULL;
	gl.line = NULL;
	gl.ln = 0;
	gl.read = NULL;
	gl.stack = NULL;
}
