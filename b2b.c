#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define wordsize 8
#define bytesize 8

void initpcword(bool pcword[]);
void printpcword(bool pcword[]);
void invertbit(bool pcword[], int n);
void inttobin(unsigned int decint, bool pcword[]);
unsigned int bintoint(bool pcword[]);

const bool down = 0;
const bool up = 0;
int main(void)
{
    bool w1[wordsize], w2[wordsize];
    initpcword(w1); 
    printpcword(w1);
    printf("%d", bintoint(w1));
    invertbit(w1, 7);
    putchar('\n');
    printpcword(w1);
    printf("%d", bintoint(w1));
    putchar('\n');
    return 0;
}
unsigned int bintoint(bool pcword[])
{
    unsigned int decint = 0;
    unsigned int x = 1;
    x = (x<< 14);
    for (int i=wordsize-1;i>0;i--)
    {
        x = x>>1;
        decint = decint + x*pcword[i];
        printf("%d %d\n", x, decint);
        if (i == 0)
            return decint;
    }
}
void inttobin(unsigned int decint, bool pcword[])
{   
    initpcword(pcword);
    int binpos;
}
void invertbit(bool pcword[], int n)
{
    pcword[n] = ~pcword[n];
}
void initpcword(bool pcword[])
{
    for (int n = 0;n<wordsize;n++)
        pcword[n] = down;
}
void printpcword(bool pcword[])
{
    for (int n = 0;n<wordsize;n++)
        printf("%d", pcword[n]);

    putchar('\n');
}
