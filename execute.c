#include "monty.h"
#include <unistd.h>

/**
 * execute - to execute commands
 * @op: the command to be checked
 * @stack: a double pointer to the top of the stack
 * @line_num: the line number of the script
 * Return: void
 */

void execute(char *op, stack_t **stack, unsigned int line_num)
{
	size_t i;

	 instruction_t codes[] = {
		 {"push", push},
		 {"pall", pall},
		 {"pint", pint},
		 {"pop", pop},
		 {"swap", swap},
		 {NULL, NULL}
	 };

	for (i = 0; codes[i].opcode != NULL; i++)
	{
		if (strcmp(codes[i].opcode, op) == 0)
		{
			codes[i].f(stack, line_num);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_num, op);
	exit(EXIT_FAILURE);
}
