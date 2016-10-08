#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void diffword(char* word1, char* word2);
int diffnumchar(char* word1, char* word2);

int main(void)
{
    
    char* word1 = "Georgios";
    char* word2 = "georgioS";
    char word3[] = "Geoorgios";
    diffword(word1, word2);
    diffnumchar(word1, word2);
    printf("%c\n", *word1);
    return 0;
}

void diffword(char* word1, char* word2)
{
    int compare = strcmp(word1, word2);
    printf("%s\n", word1);
    printf("%s\n", word2);
    printf("%d\n", compare);
}

int diffnumchar(char* word1, char* word2)
{
    int c1, c2;
    c1 = 0;
    c2 = 0;
    char* w1;
    w1 = word1;
    char* w2;
    w2 = word2;
    word1++;
    printf("%c\n", *word1);
    printf("%c\n", *w1);

    return c1-c2;
}
