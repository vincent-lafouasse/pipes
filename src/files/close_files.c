#include "t_files.h"

void close_files(t_files* files)
{
	if (!files)
		return;
	close_fd(&files->in_fd);
	close_fd(&files->out_fd);
	close_fd(&files->pipe[0]);
	close_fd(&files->pipe[1]);
}


void close_pipe_input(t_files* files)
{
	if (!files)
		return;
	close_fd(&files->pipe[READ]);
}

void close_pipe_output(t_files* files)
{
	if (!files)
		return;
	close_fd(&files->pipe[WRITE]);
}

void close_infile(t_files* files)
{
	if (!files)
		return;
	close_fd(&files->in_fd);
}

void close_outfile(t_files* files)
{
	if (!files)
		return;
	close_fd(&files->out_fd);
}

