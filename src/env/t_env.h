#pragma once

#include "error/t_error.h"

typedef struct s_env {
	char** path;
} t_env;

t_error load_env(const char** sys_env, t_env* env);