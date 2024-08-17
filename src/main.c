#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "error/t_error.h"
#include "env/t_env.h"
#include "log/log.h"
#include "command/t_command.h"

#include "libft/ft_io.h"

typedef struct s_pipex {
	t_command* cmd1;
	t_command* cmd2;
	char* infile;
	char* outfile;
	t_env env;
} t_pipex;

t_pipex t_pipex_init(void)
{
	return (
		(t_pipex){
		.cmd1 = NULL,
		.cmd2 = NULL,
		.infile = NULL,
		.outfile = NULL,
		.env = (t_env){.sys_env = NULL, .path = NULL}
	}
	);
}

t_error load_pipex_input(int ac, char** av, char** sys_env, t_pipex* out)
{
	t_error err;

	if (ac != 5)
		return  BAD_N_ARGS_ERROR;

	*out = t_pipex_init();

	err = load_env(sys_env, &out->env);
	if (err != NO_ERROR)
		return err;

	out->cmd1 = malloc(sizeof(*out->cmd1));
	out->cmd2 = malloc(sizeof(*out->cmd2));
	if (!out->cmd1 || !out->cmd2)
		return OOM_ERROR;

	err = load_command(av[2], &out->env, out->cmd1);
	if (err != NO_ERROR)
		return err;

	return load_command(av[3], &out->env, out->cmd2);
}

static void cleanup(void);
static void cleanup_exit(t_error error);

int main(int ac, char** av, char** sys_env)
{
	/*
	t_pipex pipex;
	t_error err;

	err = load_pipex_input(ac, av, sys_env, &pipex);
	if (err != NO_ERROR)
		cleanup_exit(err);

	pid_t pid = fork();

	if (pid == 0)
	{
		execve(pipex.cmd1->location, pipex.cmd1->args, sys_env);
	}
	else
	{
		wait(NULL);
		printf("\n");
		execve(pipex.cmd2->location, pipex.cmd2->args, sys_env);
	}
	*/
	t_env env;
	load_env(sys_env, &env);

	t_command cmd;
	load_command(av[1], &env, &cmd);
	
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
