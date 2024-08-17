#pragma once

#include "command/t_command.h"

typedef struct s_pipex {
	t_command* cmd1;
	t_command* cmd2;
	char* infile;
	char* outfile;
	t_env env;
} t_pipex;

t_error load_pipex_input(int ac, char** av, char** sys_env, t_pipex* out);
void cleanup_pipex_input(t_pipex* pipex);
