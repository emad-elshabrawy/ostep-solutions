#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{	
	int fd1 = open("file1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);	
	if (fd1 == -1) {
		perror("open failed");
		exit(1);
	}


	int fd2 = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);	
	if (fd2 == -1) {
		perror("open failed");
		exit(1);
	}

	pid_t p = fork();

	if (p < 0) {
		perror("fork failed");
		exit(1);		
	} else if (p == 0) {
		write(fd1, "CHILD\n", 6);
	} else {
		write(fd1, "PARENT\n", 7);
	}

	close(fd1);

	if (p == 0) {
		write(fd2, "CHILD\n", 6);
	} else if (p > 0) {
		write(fd2, "PARENT\n", 7);		
	}

	close(fd2);
	return 0;
}
