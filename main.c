#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

qs_t var;

/**
 * main - entry level - interpreter for Monty ByteCodes files
 * @argc: number of arguments passed
 * @argv: array of arguments(strings)
 * Return: EXIT_SUCCESS for success, EXIT_FAILURE for failure
 */

int main(int argc, char *argv[])
{
	char *line = NULL, *op = NULL;
	size_t n = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	FILE *fs = NULL;

	var.q_or_s = 0;
	var.qs_len = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fs = fopen(argv[1], "r");
	if (fs == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	on_exit(free_line, &line);
	on_exit(free_stack, &stack);
	on_exit(fs_close, fs);
	while (getline(&line, &n, fs) != -1)
	{
		line_number++;
		op = strtok(line, "\n\t\r ");
		if (op != NULL && op[0] != '#')
		{
			execute(op, &stack, line_number);
		}
	}
	exit(EXIT_SUCCESS);
}
