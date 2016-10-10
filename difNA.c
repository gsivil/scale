#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compare DNA sequences TAGC
// 1 2 3 4-letter words

int main(void)
{
    char* dna1 = "TAGC";
    char* dna2 = "TTGC";
    char* d1;
    d1 = dna1;
    d1++;
    d1++;
    dna1++;
    printf("%c\n", *d1);
    return 0;
}

void diffDNA(char* dna1, char* dna2)
{
    char* d1;
    char* d2;

}
