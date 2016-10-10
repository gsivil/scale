#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compare DNA sequences TAGC
// 1 2 3 4-letter words
// sequence tab sequence endline

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
    #define min(a,b) ((a) > (b) ? (b) : (a))
#endif

#define same 's'
#define dif  'd'

#define dnaDB "1.txt"
#define tabsize 3

char diffDNA(char* dna1, char* dna2);
char chareq(char d1, char d2);

int main(void)
{
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen(dnaDB, "r");
    int charatab, charbtab;
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while((read = getline(&line, &len, fp)) != -1)
    {
        charbtab = 0;
        charatab = 0;
        for (int i=0;i<strlen(line);i++)
        {
           if ((line[i] == ' ') && (charbtab == 0))
           {
               charbtab = i;
               printf("%d ", charbtab);
           };
           if (line[i] == '\n')
           {
               charatab = i-charbtab-1;
               printf("%d ", charatab);
           };
        }
        printf("%s", line);
    }
    char* dna1 = "TAGC";
    char* dna2 = "TAGC";
    char totcheck;
    totcheck =  diffDNA(dna1, dna2);
    printf("%c\n", totcheck); 
    return 0;
}
char diffDNA(char* dna1, char* dna2)
{
    char* d1 = dna1;
    char* d2 = dna2;
    int c1 = strlen(d1);
    int c2 = strlen(d2);
    char samenot;
    char totcheck = 'S';
    for (int i = 0;i<min(c1, c2);i++)
    {
        samenot = chareq(*d1, *d2);
        if (samenot == dif)
            totcheck = 'D';
        printf("%d %c %c %c\n", i, *d1++, *d2++, samenot);
    };

    char space = '_';
    if (c1 > c2)
        for (int i=c2;i<c1;i++)
        {
            samenot = chareq(*d1, *d2);
            if (samenot == dif)
                totcheck = 'D';
            printf("%d %c %c %c\n", i,  *d1++, space, samenot );
        }
    else if (c2 > c1)
        for (int i=c1;i<c2;i++)
        {
            samenot = chareq(*d1, *d2);
            if (samenot == dif)
                totcheck = 'D';
            printf("%d %c %c %c\n", i, space, *d2++, samenot );
        };

    return totcheck;
}

char chareq(char d1, char d2)
{
    char sameornot;
    if (d1 == d2)
        sameornot = same;
    else
        sameornot = dif;
    return sameornot;        
}
