#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define wordsize 8

void initpcword(bool pcword[]);
void printpcword(bool pcword[]);
void invertbit(bool pcword[], int n);

const bool down = 0;
const bool up = 0;
int main(void)
{
    bool w1[wordsize], w2[wordsize];
    initpcword(w1); 
    initpcword(w2);
    invertbit(w1, 4);
    putchar('\n');
    printpcword(w1);
    printpcword(w2);
    return 0;
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
