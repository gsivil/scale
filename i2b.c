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
    printf(" %d", bintoint(w1));
    putchar('\n');
    for (int i=0;i<wordsize;i=i+2)
        invertbit(w1, i);
//    invertallbits(w1);
    printpcword(w1);
    printf(" %d", bintoint(w1));
    putchar('\n');
    for (unsigned int x = 0;x<=pow(2, wordsize)-1; x++)
    {
        inttobin(x, w1);
        printf("%d\t", x);
        printpcword(w1);
        putchar('\n');
    };
    return 0;
}
void invertallbits(bool pcword[])
{
    for (int i =0;i<wordsize;i++)
        pcword[i] = ~pcword[i];
}
void inttobin(unsigned int decint, bool pcword[])
{
    initpcword(pcword);
    bool temppcword[wordsize];
    initpcword(temppcword);
    unsigned int x = 1;
    x = x << (wordsize - 1);
    unsigned int y = 1 << wordsize;
    unsigned int tempint  = decint;
    int i = 0;
    if (decint > y)
    {
        printf("\nThis conversion is not possible\n");
    }
    else
    while ((tempint > 0) && (i < wordsize))
    {
//        printf("%d %d %d\n", i, x, tempint);
        if (tempint >= x)
        {
            tempint = tempint - x;
            pcword[i] = up;
        }
        else
        {
            pcword[i] = down;
        };
        x = x>>1;
        i = i+1;
    }
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

}
