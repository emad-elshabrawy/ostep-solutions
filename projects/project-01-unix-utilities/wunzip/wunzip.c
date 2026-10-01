#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{	
	if (argc < 2) {
		printf("wunzip: file1 [file2 ...]\n");
		exit(1);
	}

	for (int i = 1; i < argc; ++i) {
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL) {
        		fprintf(stdout, "file doesn't exist or cannot be open.\n");
        		exit(1);
        	}
        
        	char ch;
        	int count;
        
        	
        	// Read the 4 bytes count first.
        	// Each compressed record is: [4-bytes count][1-byte character].
        	// If we cannot read the count, there are no more complete records to process.
        	// The character is read only after a valid count has been successfully read.
        	while (fread(&count, sizeof(count), 1, fp)) { // count comes first in every 5-byte record, so use it to detect  EOF.
        		fread(&ch, sizeof(ch), 1, fp);
        		while (count--) {
        			fprintf(stdout, "%c", ch);
        		}
        	} 
        	fclose(fp);
	}

	return 0;
}
