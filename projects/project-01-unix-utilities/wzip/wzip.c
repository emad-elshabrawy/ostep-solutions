#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("wzip: file1 [file2 ...]\n");
		exit(1);
	}
	
	int prev; // previous character
	int count = 0;
	for (int i = 1; i < argc; ++i) {
		FILE *fp = fopen(argv[i], "r");
		
		if (fp == NULL) {
			fprintf(stderr, "file doesn't exist or cannot be open.\n");
			exit(1);
		}
		
		int ch = fgetc(fp); // current character
        	
		if (ch == EOF && count <= 1)
			continue;

		if (prev != ch && (i%2 == 0)) { // (i%2 == 0) to check if we moved to another file or not.
			fwrite(&count, 4, 1, stdout);
			fwrite(&prev, 1, 1, stdout);
			count = 0;
			if (ch == EOF)
				continue;
		}

		prev = ch;	
		count++;
		while((ch = fgetc(fp)) != EOF) {
			if (ch == prev) {
				count++;
			}
			else {
				fwrite(&count, 4, 1, stdout);
				fwrite(&prev, 1, 1, stdout);
				count = 1;	
			}	
			prev = ch;
		}
	}
	if (count != 0) {
		fwrite(&count, 4, 1, stdout);
		fwrite(&prev, 1, 1, stdout);
	}

	return 0;
}
