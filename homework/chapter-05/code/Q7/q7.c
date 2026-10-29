#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	pid_t p = fork();

	if (p < 0) {
		perror("fork");
		exit(1);
	} else if (p == 0) {
		close(STDOUT_FILENO);
		printf("CHILD: Hello!\n");
		fflush(stdout);
		exit(0);
	} else {
		wait(NULL);
		printf("PARENT: Child finished.\n");
	}

	return 0;
}
