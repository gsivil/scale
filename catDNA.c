#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define listDNA "listDNA.txt"
#define size 4
//TAGC

char DNA[size] = {'T', 'A', 'G', 'C'};

int main(void)
{

    FILE* fp;
    fp = fopen(listDNA, "w");
    int n = 1;
    for (int i=0;i<size;i++)
    {
        fprintf(fp, "%d %c\n", n, DNA[i]);
        n = n+1;
    };
    for (int i=0;i<size;i++)
        for (int j=0;j<size;j++)
        {
            fprintf(fp, "%d %c%c\n", n, DNA[i], DNA[j]);
            n = n+1;
        };
    for (int i=0;i<size;i++)
        for (int j=0;j<size;j++)
            for (int k=0;k<size;k++)
            {
                 fprintf(fp, "%d %c%c%c\n", n, DNA[i], DNA[j], DNA[k]);
                 n = n+1;
            };

    for (int i=0;i<size;i++)
        for (int j=0;j<size;j++)
            for (int k=0;k<size;k++)
                for (int l=0;l<size;l++)
                    {
                    fprintf(fp, "%d %c%c%c%c\n", n, DNA[i], DNA[j], DNA[k], DNA[l]);
                    n = n+1;
                    };
    fclose(fp);
    return 0;
}


