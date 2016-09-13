// A program to encode, decode and manipulate png files
// PNG specification can be at https://www.w3.org/TR/PNG/
// 
#include <stdio.h> 
#define wordsize 4
#define outfile "out.png"
typedef char length_byte[wordsize];
typedef struct allchunks {
    unsigned int length[wordsize];
    char chunk_t[wordsize];
    length_byte* chunk_data[wordsize][wordsize];
    char CRC[4];
} chunk;
    
int main(void)
{
    FILE* fp;
    chunk chunk1;
    chunk1.length[0] = 'a';
    chunk1.length[1] = 'b';
    chunk1.length[2] = 'c';
    chunk1.length[3] = 'b';

    chunk1.chunk_t[0] = '1';
    chunk1.chunk_t[1] = '2';
    chunk1.chunk_t[2] = '3';
    chunk1.chunk_t[3] = '4';
     
    chunk1.chunk_data[0][0] ={'a', 'b', 'c', 'd'}; 
    chunk1.CRC[0] = 'C';
    chunk1.CRC[1] = 'D';
    chunk1.CRC[2] = 'E';
    chunk1.CRC[3] = 'F';

    fp = fopen(outfile, "w");
    char* PNGsignature = "137 80 78 71 13 10 26 10";
    fprintf(fp, "%s\n", PNGsignature);
    fclose(fp);
    return 0;
} 
