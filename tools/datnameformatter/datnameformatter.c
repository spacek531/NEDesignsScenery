#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX_DATS 1024
#define ORIGINAL_ID_LENGTH 29
#define SCENERY_ID_LENGTH 25

// 27, 23 -> 29, 25
int successfulDats = 0;
char datOriginalIds[MAX_DATS][ORIGINAL_ID_LENGTH];
char datSceneryIds[MAX_DATS][SCENERY_ID_LENGTH];


int addToGoodList(uint32_t flags, uint32_t checksum, char datname[9])
{
    if (successfulDats >= MAX_DATS)
    {
        return 1;
    }
    sprintf(datOriginalIds[successfulDats],"\"%08X|%s|%08X\"",flags,datname,checksum);
    sprintf(datSceneryIds[successfulDats++],"\"$DAT:%08X|%s\"",flags,datname);
    return 0;
}

void addToNaughtyList(char* input)
{
    printf("Failed to read\n");// %s: %d (%s)\n",input, errno, strerror(errno));
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("No file detected. Drag+Drop or list file paths in command line to format IDs\n");
        return 1;
    }
    uint32_t flags;
    uint32_t checksum;
    char datname[9];
    datname[8] = '\0';
    int bytesread;
    for (int i = 1; i < argc; i++)
    {
        errno = 0;
        FILE *f;
        f = fopen(argv[i],"rb");
        printf("%s: %d (%s)",argv[i], errno, strerror(errno));
        if (f == NULL)
        {
            printf(" f was null!\n");
            addToNaughtyList(argv[i]);
            continue;
        }
        if (successfulDats >= MAX_DATS)
        {
            printf(" [LIST TOO LONG]\n");
        }
        else
        {
            printf(" [%i]\n",successfulDats + 1);
        }
        if (!fread(&flags,4, 1, f))
        {
            addToNaughtyList(argv[i]);
            fclose(f);
            continue;
        }
        if (!fread(&datname,8, 1, f))
        {
            addToNaughtyList(argv[i]);
            fclose(f);
            continue;
        }
        if (!fread(&checksum,4, 1, f))
        {
            addToNaughtyList(argv[i]);
            fclose(f);
            continue;
        }
        addToGoodList(flags, checksum, datname);
        fclose(f);
    }
    printf("%i successful reads\n",successfulDats);
    if (!successfulDats)
    {
        while (1) {}
        return 1;
    }
    printf("****** ORIGINAL ID ******\n");
    for (int i = 0; i < successfulDats; i++)
        printf("%s\n",datOriginalIds[i]);
    printf("****** SCENERY GROUP ID ******\n");
    for (int i = 0; i < successfulDats; i++)
        printf("%s\n",datSceneryIds[i]);
    while (1) {}
    return 0;
}