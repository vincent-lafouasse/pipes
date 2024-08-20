/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:31:47 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 12:31:57 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include "command/t_command.h"
# include "env/t_env.h"

void	log_sysenv(const char **sys_env);
void	log_env(const t_env *env);
void	log_cmd(const t_command *cmd);

#endif
