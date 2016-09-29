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
        fprintf(fp1, "%c", greeting[i]);
    };
    putchar('\n');
    fclose(fp1);
    return 0;
}

void clc(void)
{
    system("clear");
}
