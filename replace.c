#include <stdio.h>
#include <string.h>

// Find all the occurances of a word in a text and replace them with a given word
int main(void)
{
    char text[] = "My name is G and A and you you you I live somewhere. What about you? Where do you live?";
    char newtext[] = "\0";
    char* token;
    char* string1 = "you";
    char* string3 = "you?";
    char* string4 = "you.";
    char* string5 = "you,";
    char* string2 = "YOU";
    token  = strtok(text, " ");
    printf("%s\n", newtext);
    int i = 0;
    while (token != NULL)
    {
        if (!strcmp(token, string1) || !strcmp(token, string3) || !strcmp(token, string4) || !strcmp(token, string5))
        {
            printf("%s ", token);
            strcat(newtext, " ");
            strcat(newtext, string2);
            i = i+1;
        }
        else
        {
            printf("%s ", token);
            strcat(newtext, " ");
            strcat(newtext, token);
        };
        token = strtok(NULL, " ");

    };
    putchar('\n');
    printf("%s\n", newtext);

    return 0;
}


