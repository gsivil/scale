#include <stdio.h>
#include <string.h>

// Find all the occurances of a word in a text and replace them with a given word

#define textsize 1000
int main(void)
{
    char text[] = "you. name is G and A and you you you I live somewhere. What about you? Where do you live?";
    int tottext = strlen(text);
    char newtext[textsize] = "\0";
    char* token;
    char* string1 = "you";
    char* string3 = "you?";
    char* string4 = "you.";
    char* string5 = "you,";
    // Here we could thing of capital letters but it would not change the code much
    char* string2 = "U";
    token  = strtok(text, " ");
    if (!strcmp(token, string1) || !strcmp(token, string3) || !strcmp(token, string4) || !strcmp(token, string5))
        {
            printf("%s ", token);
            strcat(newtext, string2);
        }
    else
        {
            printf("%s ", token);
            strcat(newtext, token);
        };
    token = strtok(NULL, " "); 
    while (token != NULL)
    {
        if (!strcmp(token, string1))
        {
            printf("%s ", token);
            strcat(newtext, " ");
            strcat(newtext, string2);
        }
        else if (!strcmp(token, string3) || !strcmp(token, string4) || !strcmp(token, string5))

        {
            printf("%s ", token);
            strcat(newtext, " ");
            strcat(newtext, string2);
            strcat(newtext, &token[strlen(token)-1]);
            strcat(newtext, " ");
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
    putchar('\n');
    int j = 0; 
    while (j< tottext)
    {
        if (text[j] == '\0')
        {
            printf(" ");
            j++;
        }
        else
            printf("%c", text[j++]);
    };
    putchar('\n');
    return 0;
}


