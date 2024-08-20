/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pipex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:30:29 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 12:30:40 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PIPEX_H
# define T_PIPEX_H

# include "command/t_command.h"

typedef struct s_pipex
{
	t_command	*cmd1;
	t_command	*cmd2;
	char		*infile;
	char		*outfile;
	t_env		env;
}				t_pipex;

t_error			load_pipex_input(int ac, char **av, char **sys_env,
					t_pipex *out);
void			cleanup_pipex_input(t_pipex *pipex);

#endif
