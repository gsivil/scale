#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Take a series of 0 and 1 and determine the statistics
// after that determine if we have bunching or not
// Choose a length of integration window and then take the average of all windows of windows of the same length then do
// a probability distribution
// If the total shots are for example 1007 and the window length is 10 the last 7 will discarded

#define data "photons.txt"

const int winlen = 20;
const long int datalen = 1000000;

int countphotons(void);
void showdata(void);
void displaydiagram(float photoprob[]);
void makedata(long int datasize, double seed);

int main(void)
{
    makedata(datalen, 0);
    FILE* fp;
    fp = fopen(data, "r");
    char nextchar = '0';
    int datasize = countphotons();
    int timeslots = datasize/winlen;
    int photinwin[timeslots];
    for (int i = 0;i<timeslots;i++)
    {
        int count = 0;
        for (int j = 0;j<winlen;j++)
        {
            nextchar = fgetc(fp);
            if (nextchar == '1')
                count = count+1;
        };
        photinwin[i] =  count;
    }; 
        
    for (int i = 0;i<timeslots;i++)
        printf("%d ", photinwin[i]); 
    float photoprob[winlen];
    for (int i = 0;i<winlen;i++)
    {
        photoprob[i] = 0;
    };
    int count  = 0;
    for (int i = 0;i<winlen;i++)
    {
        count = 0;
        for (int j=0;j<timeslots;j++)
        {
              if (photinwin[j] == i)
              {
                  count = count +1;
              };
        };
        photoprob[i] =(float) count/timeslots;
    };
    for (int i = 0;i<winlen;i++)
    {
        printf("%d %0.2f\n", i, photoprob[i]);
    };
    float normprob = 0;
    for (int i =0;i<winlen;i++)
    {
        normprob = normprob+photoprob[i];
    };
    printf("Total probability: %0.2f", normprob);
    printf("\n");
    printf("%d\n", timeslots);
    printf("%d shots\n", datasize);
    printf("The data is non-classical\n");
    showdata();
    putchar('\n');
    displaydiagram(photoprob);
    return 0;

}
void makedata(long int datasize, double seed)
{
    FILE* fp;
    srand(seed);
    fp = fopen("photons.txt", "w");
    int randomgen = 0;
    for(long int i = 0;i<datasize;i++)
    {
        randomgen = rand()%winlen;
        if (randomgen < (int) (winlen/3))
            fputc('1',fp);
        else
            fputc('0', fp);
    };
    fclose(fp);
}
void displaydiagram(float photoprob[])
{
    int discprob = 0;
    for (int i = 0;i<winlen;i++)
    {
        discprob = 200*photoprob[i];
        printf("%3.0d ", i);
        for (int j = 0;j<discprob;j++)
            putchar('*');
        printf(" %0.2f\n", 100*photoprob[i]);
    };
}
int countphotons(void)
{
    FILE* fp;
    fp = fopen(data, "r");
    char nextchar = '0';
    int i = 0;
    while (nextchar != EOF)
    {
        nextchar = fgetc(fp);
        if (nextchar != EOF)
        {
            i = i+1;
        };
    }
    fclose(fp);
    return i-1;
}

void showdata(void)
{
    FILE* fp;
    fp = fopen(data, "r");
    char nextchar = '0';
    while (nextchar != EOF)
    {
        nextchar = fgetc(fp);
        if ((nextchar != EOF) && (nextchar != '\n') && (nextchar != '\0'))
        {
            printf("%d", nextchar-'0');
        };
    }
    fclose(fp);
}
