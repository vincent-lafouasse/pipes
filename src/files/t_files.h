#pragma once

#include "error/t_error.h"

typedef struct s_files
{
	int in_fd;
	int out_fd;
	int pipe[2];
} t_files;

t_error open_files(const char* infile, const char* outfile, t_files* files);
