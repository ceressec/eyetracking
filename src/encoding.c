#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 3000
#define TAB_COUNT 117
#define true 1
#define false 0

int count_tabs(const char* string, const unsigned int len) {
	int ntabs =  0;
	for (int i = 0; i < len; i++) {
		if (string[i] == '\t') {
			ntabs++;
		}
	}
	return ntabs;
}

void replace_newline(char* string, const unsigned int len) {
	for (int i = 0; i <= len; i++) {
		if (string[i] == '\n') {
			string[i] = ' ';
		}
	}
}

int main() {
	FILE* data = fopen("data/data.tsv", "r");
	char* buffer = malloc(sizeof(char)* LINESIZE);
	char* copy = malloc(sizeof(char)* LINESIZE);
	int last_line_ok = true;

	if (data == NULL || buffer == NULL || copy == NULL) {
		exit(EXIT_FAILURE);
	}
	
	while (fgets(buffer, LINESIZE, data)) {
		if (last_line_ok) { // last line was ok
			unsigned int curr_len = strlen(buffer);
			int tab_count = count_tabs(buffer, curr_len);
			if (tab_count < TAB_COUNT) { // current line is not ok
				strcpy(copy, buffer);
				copy[curr_len -2] = ' '; // /!\ -2 -1 is \0 and -2 is \n 
				last_line_ok = false;
			} else { // current line is ok
				printf("%s", buffer);
			}
		} else { // last line was broken
			last_line_ok = true; // switch back to non broken mode
			strcat(copy, buffer); // concat strings
			int len = strlen(copy);
			replace_newline(copy, len);
			printf("%s", copy);
		}
	};

	fclose(data);
	free(buffer);
	free(copy);
	return 0;
}
