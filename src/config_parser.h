#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* Define maximum numeber of characters in a line of the config file */
#define MAX_LINE_LENGTH 100

char* getValue(FILE *fp, char *key);
// int   getValueInt(FILE *fp, char *key);

#endif
