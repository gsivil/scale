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

int main(void)
{
    
    char* word1 = "Georgios";
    char word2[] = "Georgio";
    char word3[] = "Geoorgios";
//    while(*word1 !='\0')
//    {
        printf("%c\n", *word1);
        word1++;
//    };
        printf("%c\n", *word1);
//    word1++;
 //   *word1 = 'E';
//    printf("%s\n", word1);
    return 0;
}

