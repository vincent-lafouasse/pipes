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
