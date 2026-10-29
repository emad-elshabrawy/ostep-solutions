#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid = fork();
	
	if (pid < 0) {
		perror("fork");
		exit(1);
	} else if (pid == 0) {
		printf("CHILD\n");
	} else {
		int status;
		pid_t result = waitpid(pid, &status, 0);
		if ((result == pid) && WIFEXITED(status)) {
			printf("Child exit code: %d\n", WEXITSTATUS(status));
		}
	}
	return 0;
}
