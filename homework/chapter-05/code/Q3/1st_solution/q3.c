#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t p = fork();
	
	if (p < 0) {
		perror("fork failed");
		exit(1);
	} else if (p == 0) {
		printf("hello\n");
	} else {
		sleep(1);
		printf("goodbye\n");
	}

	return 0;
}
