/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_pipex_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:30:24 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 18:58:42 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pipex.h"
#include <stdlib.h>

static t_pipex	t_pipex_init(void);

t_error	load_pipex_input(int ac, char **av, char **sys_env, t_pipex *out)
{
	t_error	err;

	out->cmd1 = malloc(sizeof(*out->cmd1));
	out->cmd2 = malloc(sizeof(*out->cmd2));
	out->env = (t_env){.sys_env = NULL, .path = NULL};
	if (!out->cmd1 || !out->cmd2)
		return (OOM_ERROR);
	if (ac != 5)
		return (BAD_N_ARGS_ERROR);
	*out = t_pipex_init();
	err = load_env(sys_env, &out->env);
	if (err != NO_ERROR)
		return (err);
	err = load_command(av[2], &out->env, out->cmd1);
	if (err != NO_ERROR)
		return (err);
	out->infile = av[1];
	out->outfile = av[4];
	return (load_command(av[3], &out->env, out->cmd2));
}

static t_pipex	t_pipex_init(void)
{
	return ((t_pipex){.cmd1 = NULL, .cmd2 = NULL, .infile = NULL,
		.outfile = NULL, .env = (t_env){.sys_env = NULL, .path = NULL}});
}
