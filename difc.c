#include <stdio.h>
#include <stdlib.h>

// A script to find trivial differences between two files
// One extra letter
// N extra letters
// Replaced letter
// One less letter
// N less letters
// the same for words
// punctuation

// First diff within a word
//
//
#define text1 "1.txt"
#define text2 "2.txt"

int main(void)
{
    FILE* fp1;
    FILE* fp2;
    
    fp1 = fopen(text1, "r");
    fp2 = fopen(text2, "r");
    char next1 = 'a';
    char next2 = 'a';
    while (((next1 = fgetc(fp1))  != EOF) && ((next2 = fgetc(fp2))  != EOF))
    {
        printf("%c", next1);
        if (next1 != next2)
            printf("*");
        printf("%c", next2);
    };
    fclose(fp2);
    fclose(fp1);
    return 0;
}

