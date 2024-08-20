/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:31:43 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 12:32:45 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include <stdio.h>

void	log_sysenv(const char **sys_env)
{
	if (!sys_env)
		return ;
	while (*sys_env)
	{
		printf("%s\n", *sys_env);
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
		printf("%s\n", env->path[i]);
		i++;
	}
}

void	log_cmd(const t_command *cmd)
{
	size_t	i;

	if (!cmd)
		return ;
	printf("path:\n%s\n", cmd->location);
	printf("args:\n");
	if (!cmd->args)
	{
		printf("None\n");
		return ;
	}
	i = 0;
	while (cmd->args[i] != NULL)
	{
		printf("%s\n", cmd->args[i]);
		i++;
	}
}
