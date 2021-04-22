#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "../headers/encoding.h"

uint16_t count_tabs(const char* string, const uint16_t len) {
	int ntabs =  0;
	for (int i = 0; i < len; i++) {
		if (string[i] == '\t') {
			ntabs++;
		}
	}
	return ntabs;
}

void replace_newline(char* string, const uint16_t len) {
	for (int i = 0; i <= len; i++) {
		if (string[i] == '\n') {
			string[i] = ' ';
		}
	}
}

void clean(FILE* data, const uint16_t TAB_COUNT, char* buffer, char* copy) {
	bool last_line_ok = true;
	while (fgets(buffer, LINESIZE, data)) {
		if (last_line_ok) { // last line was ok
			unsigned int curr_len = strlen(buffer);
			uint16_t tab_count = count_tabs(buffer, curr_len);
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
}


int main(const int argc, const char** argv) {
	FILE* data = fopen(argv[1], "r");
	char* buffer = malloc(sizeof(char)* LINESIZE);
	char* copy = malloc(sizeof(char)* LINESIZE);

	if (data == NULL || buffer == NULL || copy == NULL) {
		exit(EXIT_FAILURE);
	}
	if (fgets(buffer, LINESIZE, data) == NULL) {
		exit(EXIT_FAILURE);
	}

	const uint16_t TAB_COUNT = count_tabs(buffer, strlen(buffer)); // count tabs in header
	fseek(data, 0, SEEK_SET); // reset file pointer to beginning of file
	clean(data, TAB_COUNT, buffer, copy); // stream through file and arange it on the fly
	

	fclose(data);
	free(buffer);
	free(copy);
	return 0;
}
