#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int fd[2];

	if (pipe(fd) == -1) {
		perror("pipe");
		exit(1);
	}

	pid_t child1 = fork();

	if (child1 == -1) {
		perror("fork");
		exit(1);
	}
	if (child1 == 0) {
		close(fd[0]);
		
		if (dup2(fd[1], STDOUT_FILENO) == -1) {
			perror("dup2");
			_exit(1);
		}
		
		close(fd[1]);
		
		printf("Hello from child 1!\n");	
		fflush(stdout);
		_exit(0);
	}

	pid_t child2 = fork();

	if (child2 == -1) {
		perror("fork");
		exit(1);
	}

	if (child2 == 0) {
		close(fd[1]);

		if (dup2(fd[0], STDIN_FILENO) == -1) {
			perror("dup2");
			_exit(1);
		}
		
		close(fd[0]);
		
		char buffer[256];
		if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
			printf("Child 2 recieved: %s", buffer);
		}

		_exit(0);
	}

	close(fd[0]);
	close(fd[1]);

	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);

	return 0;
}

