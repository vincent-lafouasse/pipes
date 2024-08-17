#include "t_error.h"

const char* reprs[] = {
	"NO ERROR",
	"FORK",
	"PIPE",
	"NULL PARAM",
	"DUMMY",
	"NO PATH FOUND",
	"FILE NOT FOUND",
	"FILE NOT EXEC",
	"OOM",
};

const char* error_repr(t_error err)
{
	return reprs[err];
}
