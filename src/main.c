#include <sys/fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "error/t_error.h"
#include "command/t_command.h"
#include "t_pipex/t_pipex.h"
#include "files/t_files.h"

#include "libft/ft_io.h"

#define READ 0
#define WRITE 1

static void cleanup(t_pipex* pipex, t_files* files);
static void cleanup_exit(t_pipex* pipex, t_files* files, t_error error);

int main(int ac, char** av, char** sys_env)
{
	t_pipex pipex;
	t_files files;
	pid_t pid[2];
	t_error err;

	err = load_pipex_input(ac, av, sys_env, &pipex);
	if (err != NO_ERROR)
		cleanup_exit(&pipex, NULL, err);

	err = open_files(pipex.infile, pipex.outfile, &files);
	if (err != NO_ERROR)
		cleanup_exit(&pipex, NULL, err);

	pid[0] = fork();
	if (pid[0] == 0)
	{
		close(files.pipe[READ]);
		dup2(files.in_fd, STDIN_FILENO);
		close(files.in_fd);
		dup2(files.pipe[WRITE], STDOUT_FILENO);
		close(files.pipe[WRITE]);
		execve(pipex.cmd1->location, pipex.cmd1->args, sys_env);
	}
	
	pid[1] = fork();
	if (pid[1] == 0)
	{
		close(files.pipe[WRITE]);
		dup2(files.out_fd, STDOUT_FILENO);
		close(files.out_fd);
		dup2(files.pipe[READ], STDIN_FILENO);
		close(files.pipe[READ]);
		execve(pipex.cmd2->location, pipex.cmd2->args, sys_env);
	}

	close(files.pipe[0]);
	close(files.pipe[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	cleanup(&pipex, &files);
}

static void cleanup(t_pipex* pipex, t_files* files)
{
	if (pipex)
		cleanup_pipex_input(pipex);
	if (files)
		close_files(files);
}

static void cleanup_exit(t_pipex* pipex, t_files* files, t_error error)
{
	cleanup(pipex, files);
	ft_putstr_fd("Error:\n", STDERR_FILENO);
	ft_putstr_fd(error_repr(error), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
