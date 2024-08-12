#include <unistd.h>

int main(void)
{
	execl("ls", (char const* const)"-a", NULL);
}
