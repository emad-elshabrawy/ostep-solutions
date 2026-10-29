#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{	
	pid_t p = fork();
	
	if (p < 0) {
		perror("fork\n");
		exit(1);
	} else if (p == 0) {
		// wait(NULL); // this will return -1 imediately with errno=ECHILD, because this process has no child.
		printf("CHILD\n");
	} else {
		wait(NULL);
		printf("PARENT\n");
	}

	return 0;
}
