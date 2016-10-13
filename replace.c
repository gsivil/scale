#include <stdio.h>
#include <string.h>

// Find all the occurances of a word in a text and replace them with a given word
int main(void)
{
    char text[] = "The British Broadcasting Corporation (BBC) is a British public service broadcaster. It is headquartered at Broadcasting House in London, and is the world's oldest national broadcasting organisation[3] and the largest broadcaster in the world by number of employees, with over 20,950 staff in total, of whom 16,672 are in public sector broadcasting;[2][4][5][6][7] including part-time, flexible as well as fixed contract staff, the total number is 35,402.[8] The BBC is established under a Royal Charter[9] and operates under its Agreement with the Secretary of State for Culture, Media and Sport.[10] Its work is funded principally by an annual television licence fee[11] which is charged to all British households, companies, and organisations using any type of equipment to receive or record live television broadcasts.[12] The fee is set by the British Government, agreed by Parliament,[13] and used to fund the BBC's extensive radio, TV, and online services covering the nations and regions of the UK. From 1 April 2014, it also funds the BBC World Service, launched in 1932, which provides comprehensive TV, radio, and online services in Arabic, and Persian, and broadcasts in 28 languages.";
    char* token;
    token  = strtok(text, " ");
    printf("%s\n", token);
    int i = 0;
    while (token != NULL)
    {
        token = strtok(NULL, " ");
        if (token != NULL)
        {
            printf("%s ", token);
            if (token[strlen(token) - 1] == '.')
                i = i+1;
            printf("%c \n", token[strlen(token)-1]);
        };
    };
    printf("The text has %d sentences\n", i);
    return 0;
}


