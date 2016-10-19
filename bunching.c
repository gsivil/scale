#include <stdio.h>

// Take a series of 0 and 1 and determine the statistics
// after that determine if we have bunching or not
// Choose a length of integration window and then take the average of all windows of windows of the same length then do
// a probability distribution
// If the total shots are for example 1007 and the window length is 10 the last 7 will be normalized by takine
// (1007-10*1000/10)*10/7

#define data "photons.txt"

const int winlen = 13;
int countphotons(void);
void showdata(void);
void displaydiagram(float photoprob[]);

int main(void)
{
    FILE* fp;
    fp = fopen(data, "r");
    char nextchar = '0';
    int datasize = countphotons();
    int timeslots = datasize/winlen;
    int remainder = datasize-timeslots*winlen;
    int photinwin[timeslots+1];
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
    int count = 0;
    for (int j = 0;j<remainder;j++)
    {
        nextchar = fgetc(fp);
        if (nextchar == '1')
            count = count+1;
    };
    if (remainder != 0)
        photinwin[timeslots] = count*winlen/remainder;
    else
        photinwin[timeslots] = count;
        
    for (int i = 0;i<(timeslots+1);i++)
        printf("%d ", photinwin[i]); 
    float photoprob[winlen];
    for (int i = 0;i<winlen;i++)
    {
        photoprob[i] = 0;
    };
    for (int i = 0;i<winlen;i++)
    {
        count = 0;
        for (int j=0;j<(timeslots+1);j++)
        {
              if (photinwin[j] == i)
              {
                  count = count +1;
              };
        };
        photoprob[i] =(float) count/(timeslots+1);
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
    printf("%d %d\n", timeslots, remainder);
    printf("%d shots\n", datasize);
    printf("The data is non-classical\n");
    showdata();
    putchar('\n');
    displaydiagram(photoprob);
    return 0;

}
void displaydiagram(float photoprob[])
{
    int discprob = 0;
    for (int i = 0;i<winlen;i++)
    {
        discprob = 50*photoprob[i];
        printf("%d ", i);
        for (int j = 0;j<discprob;j++)
            putchar('*');
        printf(" %d\n", discprob);
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
