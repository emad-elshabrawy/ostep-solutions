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
		execl("/bin/ls", "ls", "-l", (char *)NULL);
		perror("excel");
		_exit(1);
	} else {
		wait(NULL);
		printf("Child finished running ls\n");
	}

	return 0;
}
