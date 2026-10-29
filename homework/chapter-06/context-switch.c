#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	int pipe1[2];
	int pipe3[2];
	if ((pipe(pipe1) == -1) || (pipe(pipe3) == -1)) {
		perror("pipe");
		return -1;
	}	
	
	char msg[] = "Hi";
	char buffer[10];
	pid_t pid = fork();

	cpu_set_t cpus;
	CPU_ZERO(&cpus);
	CPU_SET(0, &cpus);

	int N = 1000000;

	if (pid < 0) {
		perror("fork");
		return -1;
	} else if (pid == 0) {
		close(pipe1[1]);
                close(pipe3[0]);                          
		if (sched_setaffinity(0, sizeof(cpus), &cpus) == -1) {
			perror("sched_setaffinity");
			exit(EXIT_FAILURE);	
		}
		for (int i = 0; i < N; ++i) {
			read(pipe1[0], buffer, 3);
			write(pipe3[1], msg, 3);
		}
		
	} else {
		close(pipe1[0]);                        	
		close(pipe3[1]);
		if (sched_setaffinity(0, sizeof(cpus), &cpus) == -1) {
			perror("sched_setaffinity");
			exit(EXIT_FAILURE);
		}
		
		struct timeval start, end;
		if (gettimeofday(&start, NULL)) {
			perror("start");
			return -1;
		}

		for (int i = 0; i < N; ++i) {
		        write(pipe1[1], msg, 3);
		        read(pipe3[0], msg, 3);
		}

		if (gettimeofday(&end, NULL)) {
			perror("end");
			return -1;
		}
		
		double start_seconds = start.tv_sec + (start.tv_usec / 1000000.0);
		double end_seconds = end.tv_sec + (end.tv_usec / 1000000.0);
		double elapsed = end_seconds- start_seconds;
		double avg_ns = (elapsed/(2*N)) * 1e9;
		wait(&pid);

		printf("\n");
		printf("====================================\n");
		printf("     Context Switch Measurement\n");
		printf("====================================\n");
		printf("Round trips       : %d\n", N);
		printf("Estimated handoffs: %d\n", 2 * N);
		printf("Total elapsed     : %.6f seconds\n", elapsed);
		printf("Average per handoff: %.2f ns\n", avg_ns);
		printf("====================================\n");
	}
	
	return 0;
}
