/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:31:16 by poss              #+#    #+#             */
/*   Updated: 2024/08/20 12:32:44 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/t_error.h"
#include "t_files.h"
#include <fcntl.h>
#include <unistd.h>

t_error	open_files(const char *infile, const char *outfile, t_files *files)
{
	files->in_fd = open(infile, O_RDONLY);
	if (files->in_fd < 0)
		return (CANT_OPEN_FILE_ERROR);
	files->out_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (files->out_fd < 0)
	{
		close(files->in_fd);
		return (CANT_OPEN_FILE_ERROR);
	}
	if (pipe(files->pipe) == -1)
	{
		close(files->in_fd);
		close(files->out_fd);
		return (PIPE_ERROR);
	}
	return (NO_ERROR);
}
