#include <stdint.h>

#ifndef TSV_ENCODING
#define TSV_ENCODING

#define LINESIZE 3000

uint16_t count_tabs(const char* string, const uint16_t len);
void replace_newline(char* string, const uint16_t len);
void clean(FILE* data, const uint16_t TAB_COUNT, char* buffer, char* copy);

#endif