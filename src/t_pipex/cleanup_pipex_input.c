#include "t_pipex.h"

void	cleanup_pipex_input(t_pipex *pipex)
{
	if (!pipex)
		return ;
	if (pipex->cmd1)
		cleanup_command(pipex->cmd1);
	if (pipex->cmd2)
		cleanup_command(pipex->cmd2);
	cleanup_env(&pipex->env);
}
