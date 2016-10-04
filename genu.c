#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* ptr;
    char* x = "012341511342";
    char* ptr1;
    char* ptr2;
    ptr1 = &x[1];
    ptr2 = &x[7];
    char* p1, *p2;
    p1 = ptr1;
    p2 = ptr2;
    printf("%c %c\n",*ptr1, *ptr2); 
    int len = 4;
    for (int i = 0;i<len;i++)
    {
        printf("%c", *p1);
        p1++;
    };
    putchar('\n');
    for (int i = 0;i<len;i++)
    {
        printf("%c", *p2);
        p2++;
    }
    putchar('\n');
    printf("%d\n", memcmp(ptr1, ptr2, len));
    return 0;
}

