#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "error/t_error.h"

#define READ 0
#define WRITE 1

static void cleanup_exit(t_error error);

int main(void)
{
	int fd[2];
	if (pipe(fd) < 0)
		cleanup_exit(PIPE_ERROR);

	int process_id = fork();
	if (process_id == 0)
	{
		close(fd[READ]);
		int x = 69;
		printf("sending %d to child process\n", x);
		fflush(stdout);
		write(fd[WRITE], &x, sizeof(x));
		close(fd[WRITE]);
	}
	else
	{
		close(fd[WRITE]);
		int y;
		printf("receiving a number from parent process: ");
		read(fd[READ], &y, sizeof(y));
		printf("%d\n", y);
		close(fd[READ]);
	}
}

static void cleanup_exit(t_error error)
{
	(void)error;
	exit(EXIT_FAILURE);
}
