/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:31:43 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 22:21:32 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

#include <stddef.h>
#include "libft/ft_io.h"

void	log_sysenv(const char **sys_env)
{
	if (!sys_env)
		return ;
	while (*sys_env)
	{
		ft_putendl(*sys_env);
		sys_env++;
	}
}

void	log_env(const t_env *env)
{
	int	i;

	if (!env || !env->path)
		return ;
	i = 0;
	while (env->path[i])
	{
		ft_putendl(env->path[i]);
		i++;
	}
}

void	log_cmd(const t_command *cmd)
{
	size_t	i;

	if (!cmd)
		return ;
	ft_putendl("path:");
	ft_putendl(cmd->location);
	ft_putendl("args:");
	if (!cmd->args)
	{
		ft_putendl("None");
		return ;
	}
	i = 0;
	while (cmd->args[i] != NULL)
	{
		ft_putendl(cmd->args[i]);
		i++;
	}
}
