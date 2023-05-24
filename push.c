#include "monty.h"

/**
 * check_digit - checks that a string argument contains only digits
 * @arg: string to check
 *
 * Return: 0 if only digits, else 1
 */
int check_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * push - push an integer element onto the stack
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || check_digit(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.qs_len++;
}
