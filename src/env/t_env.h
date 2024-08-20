/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:30:50 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 12:31:04 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENV_H
# define T_ENV_H

# include "error/t_error.h"

typedef struct s_env
{
	char	**sys_env;
	char	**path;
}			t_env;

t_error		load_env(char **sys_env, t_env *env);
void		cleanup_env(t_env *env);

#endif
