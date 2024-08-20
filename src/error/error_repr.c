/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_repr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:32:37 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 22:11:43 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_error.h"

const char	*error_repr(t_error err)
{
	if (err == FORK_ERROR)
		return ("Error spawning new process");
	if (err == PIPE_ERROR)
		return ("Error opening UNIX pipe");
	if (err == NULL_PARAM_ERROR)
		return ("Parameter was NULL");
	if (err == NO_PATH_FOUND_ERROR)
		return ("PATH not found in system env");
	if (err == COMMAND_NOT_AVAILABLE_ERROR)
		return ("Couldn't access command");
	if (err == FILE_NOT_EXEC_ERROR)
		return ("Command is not executable");
	if (err == OOM_ERROR)
		return ("Out of memory");
	if (err == BAD_N_ARGS_ERROR)
		return ("Usage ./pipex infile cmd1 cmd2 outfile");
	if (err == CANT_OPEN_FILE_ERROR)
		return ("Error opening file");
	if (err == EXEC_ERROR)
		return ("Error executing command on child process");
	return ("Unrecognised error");
}
