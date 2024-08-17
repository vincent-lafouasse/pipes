#include "t_files.h"

#include <fcntl.h>
#include <unistd.h>

t_error open_files(const char* infile, const char* outfile, t_files* files)
{
	files->in_fd = open(infile, O_RDONLY);
	if (files->in_fd < 0)
		return DUMMY_ERROR;
	files->out_fd = open(outfile, O_WRONLY | O_CREAT, 0777);
	if (files->out_fd < 0)
	{
		close(files->in_fd);
		return  DUMMY_ERROR;
	}
	if (pipe(files->pipe) == -1)
	{
		close(files->in_fd);
		close(files->out_fd);
		return  PIPE_ERROR;
	}
	return NO_ERROR;
}
