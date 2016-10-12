#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define listDNA "listDNA.txt"



int main(void)
{
    FILE* fp;
    fp = fopen(listDNA, "w");
    char DNA[4];
    DNA[0] = 'T';
    fputc(DNA[0], fp);
    fclose(fp);
    return 0;
}
