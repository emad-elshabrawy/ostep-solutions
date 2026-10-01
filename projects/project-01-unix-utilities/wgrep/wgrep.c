#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE (512)

char* to_lowercase(char *p)
{
	for (int i = 0; *(p+i) != '\0'; ++i) {
		if (*(p+i) >= 65 && *(p+i) <= 90)
			*(p+i) = *(p+i) + 32;
	}
	return p;
}

void print_matches(FILE *fp, char *p)
{
        char *line = NULL;
	size_t len = 0;
	while (getline(&line, &len, fp) != -1) {
                if (strstr(line, p))
                        printf("%s", line);
        }
	free(line);
        fclose(fp);
}

void print_matches_i(FILE *fp, char *p)
{
	char *line = NULL;
	size_t len = 0;	
	while(getline(&line, &len, fp) != -1) {
		char copy[len];
		strcpy(copy, line);
		if (strstr(to_lowercase(copy), to_lowercase(p)))
			printf("%s", line);
	}
	free(line);
	fclose(fp);
}

void print_matches_n(FILE *fp, char *p)
{

        char *line = NULL;
	size_t len = 0;
	int line_number = 1;
	while (getline(&line, &len, fp) != -1) {
                if (strstr(line, p))
                        printf("%d. %s", line_number, line);
		++line_number;
        }
	free(line);
        fclose(fp);

}

void print_matches_v(FILE *fp, char *p)
{
	char *line = NULL;
	size_t len = 0;
	while (getline(&line, &len, fp) != -1) {
                if (!strstr(line, p))
                        printf("%s", line);
        }
	free(line);
        fclose(fp);

}

void print_matches_i_n(FILE *fp, char *p)
{
	char *line = NULL;
	size_t len = 0;
	int line_number = 1;
	while(getline(&line, &len, fp) != -1) {
		char copy[len];
		strcpy(copy, line);
		if (strstr(to_lowercase(copy), to_lowercase(p)))
                        printf("%d. %s", line_number, line);
		++line_number;
        }
	free(line);
        fclose(fp);

}

void print_matches_i_v(FILE *fp, char *p)
{
        char *line = NULL;
	size_t len = 0;
        while(getline(&line, &len, fp) != -1) {
		char copy[len];
                strcpy(copy, line);
                if (!strstr(to_lowercase(copy), to_lowercase(p)))
			printf("%s", line);
        }
	free(line);
        fclose(fp);

}

void print_matches_n_v(FILE *fp, char *p)
{
	char *line = NULL;
	size_t len = 0;
        int line_number = 1;
        while (getline(&line, &len, fp) != -1) {
                if (!strstr(line, p))
                        printf("%d. %s", line_number, line);
                ++line_number;
        }
	free(line);
        fclose(fp);

}

void print_help()
{
	printf("Usage: ./wgrep [OPTIONS] <search-term> <file>...\n");
	printf("\nSearch for a pattern in one or more files.\n");
	printf("\nOptions:\n");
	printf("  -i    case-insensitive search\n");
	printf("  -n    print line numbers\n");
	printf("  -v    print non-matching lines\n");
	printf("  --help\n");
	printf("        show this help message\n");
	exit(0);
}

void print_matches_i_n_v(FILE *fp, char *p)
{
	char *line = NULL;
	size_t len = 0;
        int line_number = 1;
        while(getline(&line, &len, fp) != -1) {
        	char copy[len];
                strcpy(copy, line);
                if (!strstr(to_lowercase(copy), to_lowercase(p)))
                        printf("%d. %s", line_number, line);
                ++line_number;
        }
	free(line);
        fclose(fp);

}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("wgrep: searchterm [file ...]\n");
		exit(1);
	}
	if (argc == 2) {
		char buffer[BUFFER_SIZE];
		while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
			if (strstr(buffer, argv[1]))			
				printf("%s", buffer);
		}
		exit(0);
	}
	bool flag_i = false;
	bool flag_n = false;
	bool flag_v = false;
	int pattern = 1; // pattern index
	while (argv[pattern][0] == '-') {
		if (argv[pattern][1] == 'i' && argv[pattern][2] == '\0') {
                        flag_i = true;
                        ++pattern;
                        continue;
                }
                if (argv[pattern][1] == 'n' && argv[pattern][2] == '\0') {
                        flag_n = true;
                        ++pattern;
                        continue;
                }
		if (argv[pattern][1] == 'v' && argv[pattern][2] == '\0') {
			flag_v = true;
			++pattern;
			continue;
		}
		if (argv[pattern][1] == '-' && argv[pattern][2] == 'h') {
			print_help();
		}
	}
	for (int i = pattern+1; i < argc; ++i) {
		FILE *fp = fopen(argv[i], "r");
        	if (fp == NULL) {
 	               	fprintf(stdout, "wgrep: cannot open file\n");
                	exit(1);
        	}

		if (flag_i && flag_n & flag_v)
			print_matches_i_n_v(fp, argv[pattern]);
		else if (flag_i && flag_n)
			print_matches_i_n(fp, argv[pattern]);
		else if (flag_i && flag_v)
			print_matches_i_v(fp, argv[pattern]);
		else if (flag_n && flag_v)
			print_matches_n_v(fp, argv[pattern]);
		else if (flag_i)
			print_matches_i(fp, argv[pattern]);
		else if (flag_n)
			print_matches_n(fp, argv[pattern]);
		else if (flag_v)
			print_matches_v(fp, argv[pattern]);
		else
			print_matches(fp, argv[pattern]);
	}
	return 0;
}
