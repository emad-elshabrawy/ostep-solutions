#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BUFFER_SIZE 512

// The order of "else if" is matter.
void print_file(FILE *fp, bool numbered, bool number_nonempty_lines, bool squeeze_blank)
{
	char buffer[BUFFER_SIZE];
	if (!numbered && !number_nonempty_lines && !squeeze_blank) {
		while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
			printf("%s", buffer);
	}
        else if (numbered && squeeze_blank) {
                int pre = 0;
                int line_number = 1;
                while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
                        if (buffer[0] == '\n' && pre == 0) {
                                printf("%d. %s", line_number++, buffer);
                                pre = 1;
                        } else if (buffer[0] == '\n' && pre == 1) {
                                continue;
                        } else if (buffer[0] != '\n' && pre == 1) {
                                printf("%d. %s", line_number++, buffer);
                                pre = 0;
                        } else { // buffer[0] != '\n' && pre == 0
                                printf("%d. %s", line_number++, buffer);
                        }
                }
        }
	else if (number_nonempty_lines && squeeze_blank) {
		int pre = 0;
                int line_number = 1;
                while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
                        if (buffer[0] == '\n' && pre == 0) {
                                printf("%s", buffer);
                                pre = 1;
                        } else if (buffer[0] == '\n' && pre == 1) {
                                continue;
                        } else if (buffer[0] != '\n' && pre == 1) {
                                printf("%d. %s", line_number++, buffer);
                                pre = 0;
                        } else { // buffer[0] != '\n' && pre == 0
                                printf("%d. %s", line_number++, buffer);
                        }
                }
	}
	else if (squeeze_blank) {
		int pre = 0;
		while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
			if (buffer[0] == '\n' && pre == 0) {
				printf("%s", buffer);
				pre = 1;
			} else if (buffer[0] == '\n' && pre == 1) {
				continue;
			} else if (buffer[0] != '\n' && pre == 1) {
				printf("%s", buffer);
				pre = 0;
			} else {
				printf("%s", buffer);
			}
		}
	}
	else if (numbered) {
                int line_number = 1;
                while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
                        printf("%d. %s", line_number++, buffer);
        }
        else if (number_nonempty_lines) {
                int line_number = 1;
                while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
                        if (buffer[0] == '\n')
                                printf("%s", buffer);
                        else
                                printf("%d. %s", line_number++, buffer);
                }
        }
	fclose(fp);
}

void print_stdin(FILE *fp)
{
	char buffer[BUFFER_SIZE];
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
		printf("%s", buffer);
	exit(0);
}
void print_help()
{
	printf("Usage: ./wcat [OPTIONS] <file>...\n");
	printf("\n");
	printf("Display the contents of one or more files.\n");
	printf("\n");
	printf("Options:\n");
	printf("  -n    number all lines\n");
	printf("  -b    number non-empty lines\n");
	printf("  -s    squeeze consecutive blank lines\n");
	printf("  --help\n");
	printf("        show this help message\n");
	exit(0);
}

int main(int argc, char *argv[])
{
	if (argc == 1) {
		FILE *fp = stdin;
		print_stdin(fp);
	}

	bool numbered = false;
	bool number_nonempty_lines = false;
	bool squeeze_blank = false;
	for (int i = 1; i < argc; ++i) {
		if (argv[i][0] == '-' && argv[i][1] == 'n' && argv[i][2] == '\0') {
			numbered = true;
			continue;
		}
		else if (argv[i][0] == '-' && argv[i][1] == 'b' && argv[i][2] == '\0') {
			number_nonempty_lines = true;
			continue;
		}
		else if (argv[i][0] == '-' && argv[i][1] == 's' && argv[i][2] == '\0') {
			squeeze_blank = true;
			continue;
		}
		else if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == 'h') {
			print_help();
		}
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL) {
			printf("wcat: cannot open file\n");
			exit(1);
		}
		print_file(fp, numbered, number_nonempty_lines, squeeze_blank);
	}

	return 0;
}
