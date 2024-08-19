#include "t_error.h"

const char* reprs[] = {
	"NO_ERROR",
	"FORK_ERROR",
	"PIPE_ERROR",
	"NULL_PARAM_ERROR",
	"DUMMY_ERROR",
	"NO_PATH_FOUND_ERROR",
	"FILE_NOT_FOUND_ERROR",
	"FILE_NOT_EXEC_ERROR",
	"OOM_ERROR",
	"BAD_N_ARGS_ERROR",
	"CANT_OPEN_FILE_ERROR",
};

const char* error_repr(t_error err)
{
	return reprs[err];
}
