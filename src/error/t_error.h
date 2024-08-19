/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_error.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:10:37 by poss              #+#    #+#             */
/*   Updated: 2024/08/19 14:43:51 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ERROR_H
#define T_ERROR_H

typedef enum e_error t_error;
enum e_error
{
	NO_ERROR,
	FORK_ERROR,
	PIPE_ERROR,
	NULL_PARAM_ERROR,
	DUMMY_ERROR,
	NO_PATH_FOUND_ERROR,
	FILE_NOT_FOUND_ERROR,
	FILE_NOT_EXEC_ERROR,
	OOM_ERROR,
	BAD_N_ARGS_ERROR,
	CANT_OPEN_FILE_ERROR,
};

const char* error_repr(t_error err);

#endif
