#include "monty.h"

/**
 * fs_close - close file stream on exit
 * @status: status passed to exit
 * @arg: pointer to file stream
 *
 * Return: void
 */
void fs_close(int status, void *arg)
{
	FILE *fs;

	(void)status;
	fs = (FILE *) arg;
	fclose(fs);
}
