#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "error/t_error.h"

#define READ 0
#define WRITE 1

static void cleanup_exit(t_error error);

static void send(int fd[2], int x)
{
	printf("sending %d to child process\n", x);
	fflush(stdout);
	write(fd[WRITE], &x, sizeof(x));
}

static void receive(int fd[2])
{
	int y;
	printf("receiving a number from parent process: ");
	read(fd[READ], &y, sizeof(y));
	printf("%d\n", y);
}

int main(void)
{
	int fd[2];
	if (pipe(fd) < 0)
		cleanup_exit(PIPE_ERROR);

	int process_id = fork();
	if (process_id == 0)
	{
		close(fd[READ]);
		send(fd, 69);
		close(fd[WRITE]);
	}
	else
	{
		close(fd[WRITE]);
		receive(fd);
		close(fd[READ]);
	}
}

static void cleanup_exit(t_error error)
{
	(void)error;
	exit(EXIT_FAILURE);
}
