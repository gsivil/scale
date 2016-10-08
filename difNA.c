#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compare DNA sequences TAGC
// 1 2 3 4-letter words

int main(void)
{
    char* dna1 = "TAGC";
    char* dna2 = "TTGC";
    dna1++;
    printf("%c\n", *dna1);
    return 0;
}
