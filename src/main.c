#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "error/t_error.h"

static void cleanup_exit(t_error error);

int main(void)
{
	int process_id = fork();

	if (process_id < 0)
		cleanup_exit(FORK_ERROR);
	if (process_id == 0)
		printf("hello from child process\n");
	else
		printf("hello from main process\n");
}

static void cleanup_exit(t_error error)
{
	(void)error;
	exit(EXIT_FAILURE);
}
