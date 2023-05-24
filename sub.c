#include "monty.h"
/**
 * sub - Subtract the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Script line number
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second_top;

	if (var.qs_len < 2)
	{
		fprintf(stderr,
			"L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second_top = top->next;

	top->n -= second_top->n;
	pop(stack, line_number);
}
