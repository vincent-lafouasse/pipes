#pragma once

#include "error/t_error.h"

typedef struct s_env
{
	char	**sys_env;
	char	**path;
}			t_env;

t_error		load_env(char **sys_env, t_env *env);
void		cleanup_env(t_env *env);
