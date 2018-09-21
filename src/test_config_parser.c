#include "config_parser.h"

int main(void)
{
    FILE * fp;
    const char *configFilename = "config.txt";
    fp = fopen(configFilename, "r");
    if (fp == NULL)
    {
        printf("Config file [%s] not found. Exiting\n", configFilename);
        exit(EXIT_FAILURE);
    }
    char *value;

    value = getValue(fp, "outgoing");
    int out = atoi(value);
    if (value) free(value);

    value = getValue(fp, "ip");
    printf("IP Addr is %s\n", value);
    if (value) free(value);

    value = getValue(fp, "incoming");
    int in = atoi(value);
    if (value) free(value);

    fclose(fp);
    printf("out = %d, in = %d\n", out, in);
    exit(EXIT_SUCCESS);
}
