#include <stdio.h>
#include <stdlib.h>

void exfun(void);
#define EXIT_SUCCESS 0

int main(void)
{
    printf("%s\n", getenv("PWD"));
    return 0;
}

void exfun(void)
{
    for (int i = 0;i<3;i++)
    {
        for (int j = 0;j<i;j++)
            printf("\t");
        printf("%d\n", i);
    };
    putchar('\n');
}
