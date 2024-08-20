/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:35:36 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 22:17:49 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command/t_command.h"
#include "execute.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static t_error	launch_process1(t_pipex *pipex, t_files *files);
static t_error	launch_process2(t_pipex *pipex, t_files *files);

t_error	execute(t_pipex *pipex, t_files *files)
{
	pid_t	pid[2];

	pid[0] = fork();
	if (pid[0] < 0)
		return (FORK_ERROR);
	if (pid[0] == 0)
		if (launch_process1(pipex, files) == EXEC_ERROR)
			return (EXEC_ERROR);
	pid[1] = fork();
	if (pid[1] < 0)
		return (FORK_ERROR);
	if (pid[1] == 0)
		if (launch_process2(pipex, files) == EXEC_ERROR)
			return (EXEC_ERROR);
	close_fd(&files->pipe[0]);
	close_fd(&files->pipe[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (NO_ERROR);
}

static t_error	launch_process1(t_pipex *pipex, t_files *files)
{
	close_pipe_input(files);
	redirect((t_redirect){.from = STDIN_FILENO, .to = files->in_fd});
	redirect((t_redirect){.from = STDOUT_FILENO, .to = files->pipe[WRITE]});
	if (execve(pipex->cmd1->location, pipex->cmd1->args, pipex->env.sys_env)
		== -1)
		return (EXEC_ERROR);
	return (UNREACHABLE);
}

static t_error	launch_process2(t_pipex *pipex, t_files *files)
{
	close_pipe_output(files);
	redirect((t_redirect){.from = STDIN_FILENO, .to = files->pipe[READ]});
	redirect((t_redirect){.from = STDOUT_FILENO, .to = files->out_fd});
	if (execve(pipex->cmd2->location, pipex->cmd2->args, pipex->env.sys_env)
		== -1)
		return (EXEC_ERROR);
	return (UNREACHABLE);
}
