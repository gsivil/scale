#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char* example = "0001.9";
    double tatof =  atof(example);
    int tatoi = atoi(example);
    long tatol = atol(example);
    long long tatoll = atoll(example);
    printf("%s %f %d %ld %lld\n", example, tatof, tatoi, tatol, tatoll);
    return 0;
}
