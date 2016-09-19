#include <stdio.h>
#include <wchar.h>

#define f1 "test.c"

int main(void)
{
    FILE* fp1, *fp2, *fp3;
    fp3 = fopen(f1,"w"); 
    fp1 = stdin;
    fp2 = stdout;
    char nextchar = 'a';
    while (nextchar !='x')
    {
        fprintf(fp2, "%c", '\b');
        fprintf(fp3,"%c", (nextchar = getc(fp1))-0);
    };
    fclose(fp3);

    return 0;
}
