/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:31:09 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 12:32:43 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/t_error.h"
#include "execute/execute.h"
#include "files/t_files.h"
#include "libft/ft_io.h"
#include "t_pipex/t_pipex.h"
#include <stdlib.h>
#include <sys/wait.h>

#define STDERR 2

static void	cleanup(t_pipex *pipex, t_files *files);
static void	cleanup_exit(t_pipex *pipex, t_files *files, t_error error);

int	main(int ac, char **av, char **sys_env)
{
	t_pipex	pipex;
	t_files	files;
	t_error	err;
	int		last_process_status;

	err = load_pipex_input(ac, av, sys_env, &pipex);
	if (err != NO_ERROR)
		cleanup_exit(&pipex, NULL, err);
	err = open_files(pipex.infile, pipex.outfile, &files);
	if (err != NO_ERROR)
		cleanup_exit(&pipex, NULL, err);
	err = execute(&pipex, &files, &last_process_status);
	if (err != NO_ERROR)
		cleanup_exit(&pipex, &files, err);
	cleanup(&pipex, &files);
	return (WEXITSTATUS(last_process_status));
}

static void	cleanup(t_pipex *pipex, t_files *files)
{
	if (pipex)
		cleanup_pipex_input(pipex);
	if (files)
		close_files(files);
}

static void	cleanup_exit(t_pipex *pipex, t_files *files, t_error error)
{
	cleanup(pipex, files);
	ft_putstr_fd("Error:\n", STDERR);
	ft_putstr_fd(error_repr(error), STDERR);
	ft_putstr_fd("\n", STDERR);
	exit(EXIT_FAILURE);
}
