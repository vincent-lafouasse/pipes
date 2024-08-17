#include <sys/fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "error/t_error.h"
#include "env/t_env.h"
#include "log/log.h"
#include "command/t_command.h"

#include "libft/ft_io.h"

#include <fcntl.h>

#define READ 0
#define WRITE 1

typedef struct s_io_files
{
	int in_fd;
	int out_fd;
	int pipe[2];
} t_io_files;

t_error open_files(const char* infile, const char* outfile, t_io_files* files)
{
	files->in_fd = open(infile, O_RDONLY);
	if (files->in_fd < 0)
		return DUMMY_ERROR;
	files->out_fd = open(outfile, O_WRONLY | O_CREAT, 0777);
	if (files->out_fd < 0)
	{
		close(files->in_fd);
		return  DUMMY_ERROR;
	}
	if (pipe(files->pipe) == -1)
	{
		close(files->in_fd);
		close(files->out_fd);
		return  PIPE_ERROR;
	}
	return NO_ERROR;
}

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

	out->infile = av[1];
	out->outfile = av[4];
	return load_command(av[3], &out->env, out->cmd2);
}

static void cleanup(t_pipex* pipex, t_io_files* files);
static void cleanup_exit(t_pipex* pipex, t_io_files* files, t_error error);

int main(int ac, char** av, char** sys_env)
{
	t_pipex pipex;
	t_io_files files;
	pid_t pid;
	t_error err;

	err = load_pipex_input(ac, av, sys_env, &pipex);
	if (err != NO_ERROR)
		cleanup_exit(&pipex, NULL, err);

	err = open_files(pipex.infile, pipex.outfile, &files);
	if (err != NO_ERROR)
		cleanup_exit(&pipex, NULL, err);

	pid = fork();
	if (pid == 0)
	{
		close(files.pipe[READ]);
		dup2(files.in_fd, STDIN_FILENO);
		execve(pipex.cmd1->location, pipex.cmd1->args, sys_env);
	}
	else
	{
		close(files.pipe[WRITE]);
		wait(NULL);
		printf("\n");
		dup2(files.out_fd, STDOUT_FILENO);
		execve(pipex.cmd2->location, pipex.cmd2->args, sys_env);
	}
	cleanup(&pipex, &files);
}

static void cleanup(t_pipex* pipex, t_io_files* files)
{
	(void)pipex;
	(void)files;
}

static void cleanup_exit(t_pipex* pipex, t_io_files* files, t_error error)
{
	cleanup(pipex, files);
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(error_repr(error), 2);
	exit(EXIT_FAILURE);
}
