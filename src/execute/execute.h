/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:32:22 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 12:32:33 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "error/t_error.h"
# include "files/t_files.h"
# include "t_pipex/t_pipex.h"

t_error	execute(t_pipex *pipex, t_files *files);

#endif
