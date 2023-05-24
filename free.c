#include "monty.h"

/**
 * free_stack - frees the stack on exit
 * @status: exit status
 * @arg: double pointer to the stack
 *
 * Return: void
 */
void free_stack(int status, void *arg)
{
	stack_t **stack_ptr;
	stack_t *next_node;

	(void)status;

	stack_ptr = (stack_t **)arg;
	if (*stack_ptr)
	{
		(*stack_ptr)->prev->next = NULL;
		(*stack_ptr)->prev = NULL;
	}
	while (*stack_ptr != NULL)
	{
		next_node = (*stack_ptr)->next;
		free(*stack_ptr);
		*stack_ptr = next_node;
	}
	var.qs_len = 0;
}

/**
 * free_line - free line returned by getline
 * @status: exit status
 * @arg: pointer to line
 *
 * Return: void
 */
void free_line(int status, void *arg)
{
	char **line = arg;

	(void)status;

	if (*line != NULL)
		free(*line);
}
