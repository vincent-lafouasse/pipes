/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:31:07 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 12:32:43 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/t_error.h"
#include "libft/ft_string.h"
#include "t_env.h"

static int	locate_path(const char **sys_env);

t_error	load_env(char **sys_env, t_env *env)
{
	int	path_index;

	path_index = locate_path((const char **)sys_env);
	if (path_index == -1)
		return (NO_PATH_FOUND_ERROR);
	env->path = ft_split(sys_env[path_index] + 5, ':');
	if (env->path == NULL)
		return (OOM_ERROR);
	env->sys_env = sys_env;
	return (NO_ERROR);
}

static int	locate_path(const char **sys_env)
{
	int	i;

	i = 0;
	while (sys_env[i])
	{
		if (ft_str_starts_with(sys_env[i], "PATH=") == true)
			return (i);
		i++;
	}
	return (-1);
}
