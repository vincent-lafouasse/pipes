#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int process_id = fork();

	if (process_id == 0)
		printf("hello from main process\n");
	else
		printf("hello from child process\n");
}
