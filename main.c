#include "monty.h"

/**
 * main - entry point for Monty interpretor
 * @argc: number of arguments
 * @argv: opcode arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *buffer = NULL;
	FD *fd;

	fopen(argv[1], NULL);

	/* wrong number of arguments */
	if (argc != 2)
		_exit(1);
	/* can't open file */
	if (FD == NULL)
		_exit(2);

}

/**
 * get_op - selects correct function to perform operation
 * @s: name of op
 * Return: pointer to function corresponding to operator
 */
int (*get_op(char *s))(struct stack_s)
{
	instruction_s ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
		};
	int i = 0;

	while (ops[i].instruction_s)
	{
		if (ops[i].instruction_s[0] == s[0] && !(*(s + 1)))
			return (ops[i].f);
		i++;
	}
	return (NULL);

/**
 * _exit - exit handler for monty program
 * @code: error number
 */

void _exit(int code, char *file)
{
	switch (code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n"); break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", file); break;
		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n", gl.ln, file); break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n"); break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", gl.ln); break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", gl.ln); break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", gl.ln); break;
		case 8:
			fprintf(stderr, "L%d: can't swap, stack too short\n", gl.ln); break;
		case 9:
			fprintf(stderr, "L%d: can't add, stack too short\n", gl.ln); break;
		case 10:
			fprintf(stderr, "L%d: can't sub, stack too short\n", gl.ln); break;
		case 11:
			fprintf(stderr, "L%d: can't div, stack too short\n", gl.ln); break;
		case 12:
			fprintf(stderr, "L%d: can't mul, stack too short\n", gl.ln); break;
		case 13:
			fprintf(stderr, "L%d: can't mod, stack too short\n", gl.ln); break;
	}
	exit(EXIT_FAILURE);
}

