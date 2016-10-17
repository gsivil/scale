#include <stdio.h>

// Take a series of 0 and 1 and determine the statistics
// after that determine if we have bunching or not
// Choose a length of integration window and then take the average of all windows of windows of the same length then do
// a probability distribution
// If the total shots are for example 1007 and the window length is 10 the last 7 will be normalized by takine
// (1007-10*1000/10)*10/7

#define data "photons.txt"

int main(void)
{
    FILE* fp;
    fp = fopen(data, "r");
    char nextchar = '0';
    while (nextchar != EOF)
    {
        nextchar = fgetc(fp);
        if (nextchar != EOF)
        {
            printf("%c", nextchar);
        };
    }
    printf("The data is non-classical\n");
    return 0;
}


