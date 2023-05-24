#include "monty.h"

/**
 * pall - prints all the values on the stack,starting from the top of the stack
 * @stack: double pointer pointing to the top of the stack
 * @line_number: index of argument/instructions
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
		{
			return;
		}
	}
}
