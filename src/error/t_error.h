/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_error.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:10:37 by poss              #+#    #+#             */
/*   Updated: 2024/08/17 14:44:02 by poss             ###   ########.fr       */
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

};

#endif
