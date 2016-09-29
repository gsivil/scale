#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clc(void);

int main(void)
{
    FILE* fp1;
    fp1 = stdout;
    char* greeting = "Hello, git!";
    clc();
    for (int i = 0;i<strlen(greeting);i++)
    {
//        fprintf(fp1, "%c", greeting[i]);
    };
    putchar('\n');
    rename("txt.jpg", "test.txt");
    char filetoremove[40];
    for (int j = 0;j<40;j++)
        filetoremove[j] = '\0';
    for (int i = 1;i<=3;i++)
    {
        sprintf(filetoremove,"%d.txt", i);
        for (int j= 0;j<40;j++)
            printf("%c", filetoremove[j]);
        putchar('\n');
        remove(filetoremove);
        for (int j= 0;j<40;j++)
            filetoremove[j] ='\0'; 
    };  
    fclose(fp1);
    return 0;
}

void clc(void)
{
    system("clear");
}
