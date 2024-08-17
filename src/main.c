#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "error/t_error.h"
#include "env/t_env.h"
#include "log/log.h"
#include "libft/ft_string.h"

typedef struct s_command {
	const char* location;
	const char** args;
	int in_fd;
	int out_fd;
} t_command;

char* full_path(const char* dir, const char* file);
t_error locate_command(const char* name, const t_env* env, char** cmd_out);
t_error load_command(t_command* cmd_out);

static void cleanup_exit(t_error error);

int main(int ac, char** av, char** sys_env)
{
	(void)ac;
	t_env env;
	t_error err;

	err = load_env((const char**)sys_env, &env);
	if (err != NO_ERROR)
		cleanup_exit(err);

	char* command_name = av[1];
	char** args = av + 2;
	char* command_location;
	err = locate_command(command_name, &env, &command_location);
	if (err != NO_ERROR)
		cleanup_exit(err);

	if (execve(command_location, args, sys_env) == -1)
		cleanup_exit(DUMMY_ERROR);
}

static void cleanup_exit(t_error error)
{
	(void)error;
	exit(EXIT_FAILURE);
}

char* full_path(const char* dir, const char* file)
{
	char* dir_with_slash;
	char* path;

	if (!dir || !file)
		return NULL;
	dir_with_slash = ft_strjoin(dir, "/");
	if (!dir_with_slash)
		return NULL;
	path = ft_strjoin(dir_with_slash, file);
	if (!path)
		return NULL;
	free(dir_with_slash);
	return path;
}

t_error locate_command(const char* name, const t_env* env, char** cmd_out)
{
	char* candidate;
	char* dir;
	int i = 0;

	dir = env->path[0];
	while (dir)
	{
		candidate = full_path(dir, name);
		if (!candidate)
			return OOM_ERROR;
		if (access(candidate, X_OK) == 0)
		{
			*cmd_out = candidate;
			return NO_ERROR;
		}
		free(candidate);
		dir = env->path[++i];
	}
	return FILE_NOT_FOUND_ERROR;
}
