#include "config_parser.h"

char* matchLine(char *str, char *key)
{
    const char* delim = "= \n";
    char buf[MAX_LINE_LENGTH];
    strncpy(buf, str, MAX_LINE_LENGTH);
    char *token, *val;
    token = strtok(buf, delim);
    if (strcmp(token, key) == 0)
    {
        token = strtok(NULL, delim);
        val   = (char *) malloc(MAX_LINE_LENGTH);
        strcpy(val, token);
        return val;
    }
    else
        return NULL;
}

/* */
char* getValue(FILE *fp, char *key)
{
    rewind(fp);
    char *line = NULL, *value = NULL;
    bool found;
    size_t len = 0;
    size_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Read line: %s\n", line);
        if ( (value = matchLine(line, key)) != NULL ) {
            found = true;
            break;
        }
    }
    if (!found) printf("\nWarning: Key [%s] not found in config file! \n", key);
    if (line) free(line);
    return value;
}

// int getValueInt(FILE *fp, char *key)
// {
//     rewind(fp);
//     char *line = NULL;
//     size_t len = 0;
//     size_t read;
//     char *value;
//     int ret;
//     while ((read = getline(&line, &len, fp)) != -1) {
//         #ifdef CONFIG_PARSER_DEBUG
//         printf("Read line: %s\n", line);
//         #endif
//         if ( (value = matchLine(line, key)) != NULL ) {
//             ret = atoi(value);
//             free(value);
//         }
//     }
//     if (line) free(line);
//     return ret;
// }

