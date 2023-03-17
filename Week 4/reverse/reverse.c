#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

const int HEADER_SIZE = 44;

int check_format(WAVHEADER *header);
int get_block_size(WAVHEADER *header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    FILE *inptr = fopen(argv[1], "rb");
    if (inptr == NULL)
    {
        printf("Can't open input file.\n");
        return 1;
    }

    // Read header into a struct
    WAVHEADER header;
    fread(&header, HEADER_SIZE, 1, inptr);
    fseek(inptr, header.subchunk1Size, SEEK_CUR);


    // Use check_format to ensure WAV format
    if (check_format(&header) == 0)
    {
        fclose(inptr);
        return 1;
    }

    // Open output file for writing
    FILE *outptr = fopen(argv[2], "wb");
    if (outptr == NULL)
    {
        printf("Can't open output file.\n");
        return 1;
    }

    // Write header to file
    fwrite(&header, sizeof(header), 1, outptr);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(&header);

   // Write reversed audio to file
    // TODO #8
    fseek(inptr, block_size, SEEK_END);

    while(ftell(inptr) - block_size > sizeof(header))
    {
        fseek(inptr, -2 * block_size, SEEK_CUR);
        BYTE c[block_size];
        fread(&c, block_size, 1, inptr);
        fwrite(&c, block_size, 1, outptr);
    }


    // Free memory and close files

    fclose(outptr);
    fclose(inptr);

    return 0;
}

int check_format(WAVHEADER *header)
{
    if (memcmp(header->format, "WAVE", 4) != 0)
    {
        printf("Error: Input file is not in the WAV format.\n");
        return 0;
    }

    return 1;
}

int get_block_size(WAVHEADER *header)
{
    int channels = header->numChannels;
    int bytes_samples = header->bitsPerSample / 8;

    return channels * bytes_samples;
}
