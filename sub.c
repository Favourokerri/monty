#include "monty.h"

/**
 * sub - sub the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 *
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (var.qs_len < 2)
	{
		fprintf(stderr,
		"L%u: can't sub, stack too short\n",
		line_number);
		exit(EXIT_FAILURE);
	}

	n -= (*stack)->n;  /* Subtract top element from the second top element */
	pop(stack, line_number);
	(*stack)->n -= n;  /* Store the result in the second top element */
}
