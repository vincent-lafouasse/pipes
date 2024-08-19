#include "t_command.h"

#include <stdlib.h>

void cleanup_command(t_command* command)
{
	int i;

	if (!command)
		return ;
	free(command->location);
	command->location = NULL;
	if (command->args)
	{
		i = 0;
		while (command->args[i])
		{
			free(command->args[i]);
			i++;
		}
		free(command->args);
	}
	command->args = NULL;
	free(command);
}
