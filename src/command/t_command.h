/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_command.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:32:02 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 12:32:46 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_COMMAND_H
# define T_COMMAND_H

# include "env/t_env.h"
# include "error/t_error.h"

typedef struct s_command
{
	char	*location;
	char	**args;
}			t_command;

t_error		load_command(const char *command, const t_env *env,
				t_command *cmd_out);
void		cleanup_command(t_command *command);

#endif
