#pragma once

#include "error/t_error.h"

#define READ 0
#define WRITE 1

typedef struct s_files
{
	int	in_fd;
	int	out_fd;
	int	pipe[2];
}		t_files;

t_error	open_files(const char *infile, const char *outfile, t_files *files);
void	close_files(t_files *files);
void	close_fd(int *fd);

void	close_pipe_input(t_files *files);
void	close_pipe_output(t_files *files);
void	close_infile(t_files *files);
void	close_outfile(t_files *files);

typedef struct s_redirect
{
	int	from;
	int	to;
}		t_redirect;

void	redirect(t_redirect fds);
