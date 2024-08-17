#pragma once

#include "env/t_env.h"
#include "command/t_command.h"

void log_sysenv(const char** sys_env);
void log_env(const t_env* env);
void log_cmd(const t_command* cmd);
