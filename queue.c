#include "monty.h"

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
