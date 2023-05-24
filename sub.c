#include "monty.h"

/**
 * add - add the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 *
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->next->next->n - (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->next->n = n;
}
