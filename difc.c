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
void diffword(char* word1, char* word2);

int main(void)
{
    
    char* word1 = "Georgios";
    char* word2 = "Heorgios";
    char word3[] = "Geoorgios";
    diffword(word1, word2);
    return 0;
}

void diffword(char* word1, char* word2)
{
    printf("%c\n", *word1);
    printf("%c\n", *word2);
}
