#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "error/t_error.h"
#include "env/t_env.h"
#include "log/log.h"
#include "command/t_command.h"

#include "libft/ft_io.h"

static void cleanup(void);
static void cleanup_exit(t_error error);

int main(int ac, char** av, char** sys_env)
{
	(void)ac;
	t_command cmd;
	t_env env;
	t_error err;

	if (ac == 1)
		return 0;

	err = load_env((const char**)sys_env, &env);
	if (err != NO_ERROR)
		cleanup_exit(err);

	err = load_command(av[1], av + 2, ac - 2, &env, &cmd);
	if (err != NO_ERROR)
		cleanup_exit(err);

	log_cmd(&cmd);
	execve(cmd.location, cmd.args, sys_env);
	/*
	char* command_name = av[1];
	char** args = av + 2;
	char* command_location;
	err = locate_command(command_name, &env, &command_location);
	if (err != NO_ERROR)
		cleanup_exit(err);

	if (execve(command_location, args, sys_env) == -1)
		cleanup_exit(DUMMY_ERROR);
	*/
}

static void cleanup(void)
{}

static void cleanup_exit(t_error error)
{
	cleanup();
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(error_repr(error), 2);
	exit(EXIT_FAILURE);
}
