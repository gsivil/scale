#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("wget https://arxiv.org/robots.txt -O foo.html");
    putchar('\n');
    return 0;
}

