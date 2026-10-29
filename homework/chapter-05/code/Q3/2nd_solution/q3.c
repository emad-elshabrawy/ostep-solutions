#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd[2];
	if (pipe(fd) == -1) {
		perror("pipe failed\n");
		exit(1);
	}

	pid_t p = fork();
	if (p < 0) {
		perror("fork failed\n");
		exit(1);
	} else if (p == 0) {
		close(fd[0]);
		printf("hello\n");
		write(fd[1], "x", 1);
		close(fd[1]);
	} else {
		close(fd[1]);
		char c;
		read(fd[0], &c, 1);
		printf("goodbye\n");
		close(fd[0]);
	}

	return 0;
}
