/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:30:46 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 18:59:24 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_env.h"
#include <stdlib.h>

void	cleanup_env(t_env *env)
{
	int	i;

	if (!env)
		return ;
	env->sys_env = NULL;
	i = 0;
	if (env->path)
	{
		while (env->path[i])
		{
			free(env->path[i]);
			i++;
		}
		free(env->path);
	}
	env->path = NULL;
}
