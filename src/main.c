#include <sys/fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "error/t_error.h"
#include "env/t_env.h"
#include "log/log.h"
#include "command/t_command.h"
#include "t_pipex/t_pipex.h"

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

static void cleanup(t_pipex* pipex, t_io_files* files);
static void cleanup_exit(t_pipex* pipex, t_io_files* files, t_error error);

int main(int ac, char** av, char** sys_env)
{
	t_pipex pipex;
	t_io_files files;
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
		// child process 1
		close(files.pipe[READ]);
		dup2(files.in_fd, STDIN_FILENO);
		close(files.in_fd);
		dup2(files.pipe[WRITE], STDOUT_FILENO);
		close(files.pipe[WRITE]);
		execve(pipex.cmd1->location, pipex.cmd1->args, sys_env);
	}
	else
	{
		close(files.pipe[WRITE]);
		dup2(files.out_fd, STDOUT_FILENO);
		close(files.out_fd);
		dup2(files.pipe[READ], STDIN_FILENO);
		close(files.pipe[READ]);
		wait(NULL);
		printf("\n");
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
