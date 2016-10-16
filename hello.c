#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define picture "dots.pgm"
#define metadots "metadots.pgm"

// Use struct to save the dot location

void makeheaders(char* pict, char* comment, int dimx, int dimy, int range);
void makepicture(char* pict, char* comment, int dimx, int dimy, int range);
void makedata(char* pict, int dimx, int dimy, int range);
int countdots(char* pict);

int main(void)
{
     
//    The following create the picture that we will be processing
//    FILE* fp1;
//    int dimx, dimy, range;
//    dimx = 200;
//    dimy = 200;
//    range = 15;
//    char* comment = "#Dots at random positions";
//makepicture(picture, comment, dimx, dimy, range);
    countdots(metadots); 
    putchar('\n');
    return 0;
}
int countdots(char* pict)
{
    FILE* fp;
    fp = fopen(pict, "r");
    char* token;
    char line[1000];
    while(fgets(line, sizeof(line), fp))
    {
        token = strtok(line, "");
        while (token != NULL)
        {
             printf("%s", token);
             token =  strtok(NULL, " ");
//             if (*token) 
                 printf("dot");
        };
    };
    fclose(fp);
    return 0;
}
void makepicture(char* pict, char* comment, int dimx, int dimy, int range)
{
    makeheaders(pict, comment, dimx, dimy, range);
    makedata(pict, dimx, dimy, range);

}
void makedata(char* pict, int dimx, int dimy, int range)
{
    FILE* fp1;
    fp1 = fopen(pict, "a");
    int thres = 14;
    for (int i= 0;i<dimy;i++)
    {
        for (int j=0;j<dimx;j++)
        {
            if ((rand()%(range+1) > thres) && (rand()%(range+1) > thres))
                fprintf(fp1, "%d ",  rand()%(range+1));
            else
                fprintf(fp1, "%d ", 0);
        }
        fprintf(fp1, "\n");
    };
    fclose(fp1);
}

void makeheaders(char* pict, char* comment, int dimx, int dimy, int range)
{
    FILE* fp1;
    fp1 = fopen(pict, "w");
    fprintf(fp1, "P2\n");
    fprintf(fp1, comment);
    fprintf(fp1, "\n");
    fprintf(fp1, "%d %d\n", dimx, dimy);
    fprintf(fp1, "%d\n", range);
    fclose(fp1);
};
