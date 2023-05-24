#include "monty.h"

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (var.qs_len == 0)
	{
		fprintf(stderr,
			"L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if (var.qs_len != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(current);
	var.qs_len--;
}
