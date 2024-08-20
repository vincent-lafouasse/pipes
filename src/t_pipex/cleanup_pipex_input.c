/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_pipex_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:30:43 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 12:30:44 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pipex.h"

void	cleanup_pipex_input(t_pipex *pipex)
{
	if (!pipex)
		return ;
	if (pipex->cmd1)
		cleanup_command(pipex->cmd1);
	if (pipex->cmd2)
		cleanup_command(pipex->cmd2);
	cleanup_env(&pipex->env);
}
