#include "monty.h"

/**
 * pop - removes the top element off the stack
 * @stack: double pointer to the top of stack
 * @line_number: line number of current instruction
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (var.qs_len == 0 || *stack == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
		(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	free(current);
	var.qs_len--;
}
