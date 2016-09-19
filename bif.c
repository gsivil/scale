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
    long int pos  = 0;
    while (nextchar !='x')
    {
        fprintf(fp2, "\b%c", '\b');
        pos = ftell(fp3);
        if (pos%3 == 0)
        {
            fseek(fp3, pos, SEEK_SET);
            printf("%ld ", pos);
        };
        fprintf(fp3,"%c", (nextchar = getc(fp1))-0);
    };
    fclose(fp3);

    return 0;
}
