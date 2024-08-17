#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "error/t_error.h"

typedef struct s_env {
	const char** raw_env;
	const char* bin;
	const char** bin_dirs;
} t_env;

typedef struct s_command {
	const char** name;
	const t_env* env;
	int in_fd;
	int out_fd;
} t_command;

static void cleanup_exit(t_error error);

int main(int ac, char** av, char** env)
{
	(void)ac;
	(void)av;

	char* args[] = {"-l", NULL};

	if (execve("/bin/ls", args, env) == -1)
		cleanup_exit(DUMMY_ERROR);
}

static void cleanup_exit(t_error error)
{
	(void)error;
	exit(EXIT_FAILURE);
}
