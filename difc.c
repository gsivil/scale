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

    printf("%c\n", *word1);
    putchar('\n');
    printf("%d\n", diffnumchar(word1, word2));
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
    int c1 = 0;
    int  c2 = 0;
    char* w1 = word1;
    char* w2 = word2;
    while ( *word1 != '\0')
    {
        printf("%d.%c ", c1++, *word1++);
    };
    putchar('\n');
    while ( *word2 != '\0')
    {
        printf("%d.%c ", c2++, *word2++);
    };
    putchar('\n');

    return c1-c2;
}
