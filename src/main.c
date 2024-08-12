#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int pid = fork();

	printf("hello from %d\n", pid);
}
