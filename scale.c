// A program to encode, decode and manipulate png files
// PNG specification can be at https://www.w3.org/TR/PNG/
// 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define wordsize 4
#define outfile "out.png"
typedef char length_byte[wordsize];
typedef struct allchunks {
    unsigned int length[wordsize];
    char chunk_t[wordsize];
    length_byte chunk_data[wordsize][wordsize];
    char CRC[4];
} chunk;
// Critical chunks
// http://www.libpng.org/pub/png/spec/1.2/PNG-Chunks.html
// IHDR first chunk 13 bytes width, height, bit depth, color type, compression method, filter method, and interlace
//
//  Width:              4 bytes
//  Height:             4 bytes
//  Bit depth:          1 byte
//  Color type:         1 byte
//  Compression method: 1 byte
//  Filter method:      1 byte
//  Interlace method:   1 byte
//
//
// method
// PLTE contains the palette aka list of colors
// IDAT contains the image, split it in multiple IDAT chunks for simplicity
// IEND marks the image end
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
    char cdata[4]; 
    cdata[0] = 'a';
    cdata[1] = '1';
    cdata[2] = 'b';
    cdata[3] = '2';
    strcpy(chunk1.chunk_data[0][0],cdata); 
    chunk1.CRC[0] = 'C';
    chunk1.CRC[1] = 'D';
    chunk1.CRC[2] = 'E';
    chunk1.CRC[3] = 'F';

    printf("%c %c %c %c\n", chunk1.length[0], chunk1.length[1], chunk1.length[2], chunk1.length[3]);
    fp = fopen(outfile, "w");
    char* PNGsignature = "137 80 78 71 13 10 26 10";
    fprintf(fp, "%s\n", PNGsignature);
    fclose(fp);
    return 0;
} 