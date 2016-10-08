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
// We need a way to tell if the words that we are comparing were meant to be the same example: goat goAt or goat goal.
// This in our case has to be a simple and not 100% correct test
// Test the frequency of appearance of characters and if it is 50% or more consider the words the same
void diffword(char* word1, char* word2);
int diffnumchar(char* word1, char* word2);
int countchars(char* word1);

int main(void)
{
    
    char* word1 = "Georgios";
    char* word2 = "Georgi";
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
    c1 = countchars(w1);
    c2 = countchars(w2);

    return c1-c2;
}

int countchars(char* word1)
{
    int c1 = 0;
    char* w1 = word1;
    while(*w1 != '\0')
    {
        c1++;
        w1++;
    };
    return c1;
}


int sameword(int letters[26], char* word1, char* word2)
{

}
