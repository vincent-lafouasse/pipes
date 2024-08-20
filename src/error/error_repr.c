/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_repr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:32:37 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 20:40:19 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_error.h"

const char	*reprs[] = {
	"NO_ERROR",
	"FORK_ERROR",
	"PIPE_ERROR",
	"NULL_PARAM_ERROR",
	"DUMMY_ERROR",
	"NO_PATH_FOUND_ERROR",
	"COMMAND_NOT_AVAILABLE_ERROR",
	"FILE_NOT_EXEC_ERROR",
	"OOM_ERROR",
	"BAD_N_ARGS_ERROR",
	"CANT_OPEN_FILE_ERROR",
};

const char	*error_repr(t_error err)
{
	return (reprs[err]);
}
