#include "error/t_error.h"
#include "t_env.h"

#include "libft/ft_string.h"

static int locate_path(const char** sys_env);

t_error load_env(const char** sys_env, t_env* env)
{
	int path_index;

	path_index = locate_path(sys_env);
	if (path_index == -1)
		return NO_PATH_FOUND_ERROR;

	env->path = ft_split(sys_env[path_index] + 5, ':');
	if (env->path == NULL)
		return OOM_ERROR;
	return NO_ERROR;
}

static int locate_path(const char** sys_env)
{
	int i = 0;

	while (sys_env[i])
	{
		if (ft_str_starts_with(sys_env[i], "PATH=") == true)
			return i;
		i++;
	}
	return -1;
}
