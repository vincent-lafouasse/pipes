#pragma once

#include "env/t_env.h"
#include "error/t_error.h"

typedef struct s_command
{
	char	*location;
	char	**args;
}			t_command;

t_error		load_command(const char *command, const t_env *env,
				t_command *cmd_out);
void		cleanup_command(t_command *command);
