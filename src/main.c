#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "error/t_error.h"
#include "env/t_env.h"
#include "log/log.h"

typedef struct s_command {
	const char* location;
	const char** args;
	int in_fd;
	int out_fd;
} t_command;

char* locate_command(const char* name, const t_env* env)
{
	(void)name;
	(void)env;
	return NULL;
}

static void cleanup_exit(t_error error);

int main(int ac, char** av, char** sys_env)
{
	(void)ac;
	(void)av;
	t_env env;
	t_error err;

	err = load_env((const char**)sys_env, &env);
	if (err != NO_ERROR)
		cleanup_exit(err);
	log_env(&env);

	char* command_name = "ls";
	char* args[] = {"-l", NULL};
	char* command_location = locate_command(command_name, &env);

	if (execve("/bin/ls", args, sys_env) == -1)
		cleanup_exit(DUMMY_ERROR);
}

static void cleanup_exit(t_error error)
{
	(void)error;
	exit(EXIT_FAILURE);
}
