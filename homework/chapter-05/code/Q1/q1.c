#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int x = 100;
	printf("The initial value of x is: %d\n", x);	

	pid_t p = fork();
	if (p < 0) {
		perror("fork fail");
		exit(1);
	} else if (p == 0) { // Child process
		printf("I'm the child, and the value of x before I changed it is: %d\n", x);
		x = 200;
		printf("I'm the child, and the value of x after I changed it is: %d\n", x);
	} else { // Parent process
		printf("I'm the parent, and the value of x before I changed it is: %d\n", x);
		x = 300;
		printf("I'm the parent, and the value of x after I changed it is: %d\n", x);
	}
	return 0;
}
