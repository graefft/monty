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
	char *which_op, *push_op, *delim = " \t\r\n";
	size_t bufsize = 0;

	initialize();
	if (argc != 2)
		exit_helper(1, NULL);
	gl.monty = fopen(argv[1], "r");
	if (gl.monty == NULL)
		exit_helper(2, argv[1]);
	while (getline(&gl.line, &bufsize, gl.monty) != EOF)
	{
		gl.ln++;
		which_op = strtok(gl.line, delim);
		if (which_op == NULL || *which_op == '#')
			continue;
		if (strcmp(which_op, "push") == 0)
		{
			push_op = strtok(NULL, delim);
			if (!push_op)
				exit_helper(5, NULL);
			if (gl.qs == false)
				opcode_push(&gl.stack, push_op);
			else if (gl.qs == true)
				opcode_queue(&gl.stack, push_op);
			continue;
		}
		if (get_op(&gl.stack, which_op) < 0)
			exit_helper(3, gl.line);
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
		{"stack", set_stack},
		{"queue", set_queue},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"add", opcode_add},
		{"nop", opcode_nop},
		{"sub", opcode_sub},
		{"mul", opcode_mul},
		{"div", opcode_div},
		{"mod", opcode_mod},
		{"pchar", opcode_pchar},
		{"pstr", opcode_pstr},
		{"rotl", opcode_rotl},
		{"rotr", opcode_rotr},
		{NULL, NULL}
		};

	op = strtok(which, " \n");

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
			free_everything();
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
	gl.qs = false;
}
