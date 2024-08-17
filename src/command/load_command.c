#include "t_command.h"

#include <stdlib.h>
#include <unistd.h>
#include "libft/ft_string.h"
#include "libft/string.h"

static char* full_path(const char* dir, const char* file);
static t_error locate_command(const char* name, const t_env* env, char** cmd_out);
static void free_str_array(char** arr, size_t n);
static char** duplicate_args(char** args, size_t n_args, char* name);

t_error load_command(char* name, char** args, size_t n_args, const t_env* env,t_command* cmd_out)
{
	t_error err;

	err = locate_command(name, env, &cmd_out->location);
	if (err != NO_ERROR)
		return err;
	cmd_out->args = duplicate_args(args, n_args, name);
	if (cmd_out->args == NULL)
		return OOM_ERROR;
	return NO_ERROR;
}

static t_error locate_command(const char* name, const t_env* env, char** cmd_out)
{
	char* candidate;
	char* dir;
	int i = 0;

	dir = env->path[0];
	while (dir)
	{
		candidate = full_path(dir, name);
		if (!candidate)
			return OOM_ERROR;
		if (access(candidate, X_OK) == 0)
		{
			*cmd_out = candidate;
			return NO_ERROR;
		}
		free(candidate);
		dir = env->path[++i];
	}
	return FILE_NOT_FOUND_ERROR;
}

static char* full_path(const char* dir, const char* file)
{
	char* dir_with_slash;
	char* path;

	if (!dir || !file)
		return NULL;
	dir_with_slash = ft_strjoin(dir, "/");
	if (!dir_with_slash)
		return NULL;
	path = ft_strjoin(dir_with_slash, file);
	if (!path)
		return NULL;
	free(dir_with_slash);
	return path;
}

static char** duplicate_args(char** args, size_t n_args, char* name)
{
	char** out;
	size_t i;

	out = malloc((2 + n_args) * sizeof(char*));
	if (!out)
		return NULL;
	out[0] = ft_strdup(name);
	if (!out[0])
		return free(out), NULL;
	i = 0;
	while (i < n_args)
	{
		out[i + 1] = ft_strdup(args[i]);
		if (!out[i + 1])
			return free_str_array(out, i + 1), NULL;
		i++;
	}
	out[n_args + 1] = NULL;
	return out;
}

static void free_str_array(char** arr, size_t n)
{
	size_t i;

	if (!arr)
		return ;
	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
