#include <stdio.h>

int main(void)
{
    FILE* fp1;
    fp1 = stdout;
    fprintf(fp1, "%s\n", "Hello, github!");
    fclose(fp1);
    return 0;
}
