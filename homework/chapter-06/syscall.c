#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#define BUFFER_SIZE 512
#define iterations 1000000

int main()
{
	int fp = open("file.txt", O_RDONLY);
	if (fp == -1) {
		perror("open");
		return(1);
	}	

	char buffer[BUFFER_SIZE];
	struct timeval start, end;

	if (gettimeofday(&start, NULL) == -1) {
    		perror("gettimeofday");
    		close(fp);
    		return 1;
	}

	for (int i = 0; i < iterations; ++i) {
		ssize_t result = read(fp, buffer, 0);
		if (result == -1) {
        		perror("read");
        		close(fp);
        		return 1;
		}
	}

	if (gettimeofday(&end, NULL) == -1) {
    		perror("gettimeofday");
    		close(fp);
    		return 1;
	}	

	double start_seconds = start.tv_sec + (start.tv_usec/1000000.0);
	double end_seconds = end.tv_sec + (end.tv_usec/1000000.0);
	double elapsed = end_seconds - start_seconds;

	printf("System Call Measurement Results\n");
	printf("--------------------------------\n");
	printf("Number of read() calls : %d\n", iterations);
	printf("Total elapsed time     : %.6f seconds\n", elapsed);
	printf("Average time per call  : %.2f ns\n", (elapsed / iterations) * 1e9);

	close(fp);
	return 0;
}
