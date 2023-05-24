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

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the top of the stack
 * @line_num: script line number
 *
 * Return: void
 */
void queue(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
	var.q_or_s = QUEUE;
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the top of stack
 * @line_number: line number of current instruction
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (var.qs_len < 2)
	{
		fprintf(stderr,
			"L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (var.qs_len == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	next = (*stack)->next;
	next->prev = (*stack)->prev;
	(*stack)->prev->next = next;
	(*stack)->prev = next;
	(*stack)->next = next->next;
	next->next->prev = *stack;
	next->next = *stack;
	*stack = next;
}

/**
 * sub -  substracts the first two nodes of the stack
 * @stack: stack given by main
 * @line_number: line counter
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = result;
}
