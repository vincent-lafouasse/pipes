#pragma once

#include "error/t_error.h"
#include "env/t_env.h"

typedef struct s_command {
	char* location;
	char** args;
	int in_fd;
	int out_fd;
} t_command;

t_error load_command(char* name, char** args, const t_env* env,t_command* cmd_out);
t_error exec_command(void);
