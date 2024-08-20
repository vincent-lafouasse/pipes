#include "t_files.h"
#include <unistd.h>

void	redirect(t_redirect fds)
{
	dup2(fds.to, fds.from);
	close(fds.to);
}
