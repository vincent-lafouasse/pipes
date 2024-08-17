#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "error/t_error.h"
#include "log/log.h"
#include "libft/ft_string.h"

typedef struct s_env {
	const char** path;
} t_env;

int locate_path(const char** sys_env)
{
	int i = 0;

	while (sys_env[i])
	{
		if (ft_str_starts_with(sys_env[i], "PATH=") == true)
			return i;
		i++;
	}
	return -1;
}

t_error load_env(const char** sys_env, t_env* env)
{
	int raw_path_index;

	raw_path_index = locate_path(sys_env);
	if (raw_path_index == -1)
		return DUMMY_ERROR;
	printf("%s\n", sys_env[raw_path_index]);

	env->path = NULL;
	return NO_ERROR;
}

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
