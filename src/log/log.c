#include "log.h"

#include <stdio.h>

void log_env(const char** sys_env)
{
	if (!sys_env)
		return;

	while (*sys_env)
	{
		printf("%s\n", *sys_env);
		sys_env++;
	}
}
