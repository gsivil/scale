#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compare DNA sequences TAGC
// 1 2 3 4-letter words
// sequence tab sequence endline
// Find if a word is a DNA sequence and if yes find the number

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
    #define min(a,b) ((a) > (b) ? (b) : (a))
#endif

#define same 's'
#define dif  'd'

#define dnaDB "listDNA.txt"
#define tabsize 3

char diffDNA(char* dna1, char* dna2);
char chareq(char d1, char d2);
void printDNAdb(char* DB);
int checkDNA(char* dna1);

int main(void)
{

        
//    printDNAdb(dnaDB);
    char* dna1 ="CC";
    checkDNA(dna1);
    return 0;
}

int checkDNA(char* dna1)
{
    FILE* fp;
    fp = fopen(dnaDB, "r");
    char* line = NULL;
    char* token;
    size_t len = 0;
    ssize_t read;
    char s1[2] = " ";
    char s2[2] = "\n";
    char* num;
    char testeq;
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while((read = getline(&line, &len, fp)) != -1)
    {
        //printf("%s", line);
        if (token != NULL)
        {
            num  = strtok(line, s1);
            printf("%s ", num);
            token  = strtok(NULL, s2);
            testeq = diffDNA(dna1, token); 
            if (testeq == 'S')
            {
                printf("%s %c\n", token, testeq);
                break;
            }
            else
            {
                printf("%s %c\n", token, testeq);
            };
        };
    };
    
    fclose(fp);
    char sameDNA = 'D';
    if (testeq == 'S')
        sameDNA = 1;
    else
    {
        sameDNA = 0;
        printf("\nNot found\n");
    };
    return 0;
}
char diffDNA(char* dna1, char* dna2)
{
    char* d1 = dna1;
    char* d2 = dna2;
    int c1 = strlen(d1);
    int c2 = strlen(d2);
    char samenot;
    char totcheck;
    if (c1 == c2)
    {
        totcheck = 'S';
        for (int i = 0;i<c1;i++)
        {
            samenot = chareq(*d1, *d2);
            d1++;
            d2++;
            if (samenot == dif)
                totcheck = 'D';
        };
    }
    else
        totcheck = 'D';
    printf("\t");
    return totcheck;
}

char chareq(char d1, char d2)
{
    char sameornot;
    if (d1 == d2)
    {
        sameornot = same;
        printf("S");
    }
    else
    {
        sameornot = dif;
        printf("D");
    };
    return sameornot;        
}
void printDNAdb(char* DB)
{
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen(DB, "r");
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
    };
    fclose(fp); 
}
