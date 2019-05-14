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

	fopen(argv[1], 
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

void _exit(int code)
{
	if (strcmp(
	exit(EXIT_FAILURE);
}
