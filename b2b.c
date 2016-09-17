#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define wordsize 8 

void initpcword(bool pcword[]);
void printpcword(bool pcword[]);
void invertbit(bool pcword[], int n);
void inttobin(unsigned int decint, bool pcword[]);
unsigned int bintoint(bool pcword[]);
void invertallbits(bool pcword[]);

const bool down = 0;
const bool up = 1;
int main(void)
{
    bool w1[wordsize], w2[wordsize];
    initpcword(w1); 
    printpcword(w1);
    printf("%d", bintoint(w1));
    putchar('\n');
    invertallbits(w1);
    printpcword(w1);
    printf("%d", bintoint(w1));
    putchar('\n');
    return 0;
}
void invertallbits(bool pcword[])
{
    for (int i =0;i<wordsize;i++)
        pcword[i] = ~pcword[i];
}
unsigned int bintoint(bool pcword[])
{
    unsigned int decint = 0;
    unsigned int x = 1;
    for (int i=0;i<wordsize;i=i+1)
    {
        decint = decint + x*pcword[wordsize-i-1];
        x = x << 1;
    }
    return decint;
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
