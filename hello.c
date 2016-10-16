#include <stdio.h>

#define picture "dots.pgm"

void makeheaders(char* pict, char* comment, int dimx, int dimy, int range);

int main(void)
{
    
    FILE* fp1;
    int dimx, dimy, range;
    dimx = 200;
    dimy = 200;
    range = 15;
    makeheaders(picture, "#test comment", dimx, dimy, range);
    fp1 = fopen(picture, "a");
    for (int i= 0;i<dimx;i++)
    {
        for (int j=0;j<dimy;j++)
        {
            if ((i == 100) && (j == 103))
                fprintf(fp1, "%d ", range+1);
            else
                fprintf(fp1, "%d ", 0);
        }
        fprintf(fp1, "\n");
    };
    putchar('\n');
    return 0;
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
