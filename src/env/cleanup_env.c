#include "t_env.h"
#include <stdlib.h>

void	cleanup_env(t_env *env)
{
	int	i;

	if (!env)
		return ;
	env->sys_env = NULL;
	i = 0;
	while (env->path[i])
	{
		free(env->path[i]);
		i++;
	}
	free(env->path);
	env->path = NULL;
}
