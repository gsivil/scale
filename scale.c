// A program to encode, decode and manipulate png files
// PNG specification can be at https://www.w3.org/TR/PNG/
// 
#include <stdio.h> 

#define outfile "out.png"

int main(void)
{
    FILE* fp;
    fp = fopen(outfile, "w");
    char* PNGsignature = "137 80 78 71 13 10 26 10";
    fprintf(fp, "%s\n", PNGsignature);
    fclose(fp);
    return 0;
}
