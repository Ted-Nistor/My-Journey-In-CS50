#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER *header);
int get_block_size(WAVHEADER *header);
const int HEADER_SIZE = 44;


int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }
    // Open input file for reading
    // TODO #2
    FILE *infile = fopen(argv[1], "rb");
    if (infile == NULL)
    {
        printf("Can't open input file\n");
        return 2;
    }
    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, HEADER_SIZE, 1, infile);
    fseek(infile, header.subchunk1Size, SEEK_CUR);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(&header) == 0)
    {
        printf("Input file is not of WAV format\n");
        return 3;
    }

    // Open output file for writing
    // TODO #5
    FILE *outfile = fopen(argv[2], "wb");
    if (outfile == NULL)
    {
        printf("Can't open output file\n");
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(header), 1, outfile);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(&header);

    // Write reversed audio to file
    // TODO #8
    fseek(infile, block_size, SEEK_END);
    while (ftell(infile) - block_size > sizeof(header))
    {
        fseek(infile, -2 * block_size, SEEK_CUR);
        BYTE buffer[block_size];
        fread(&buffer, block_size, 1, infile);
        fwrite(&buffer, block_size, 1, outfile);
    }
    fclose(outfile);
    fclose(infile);
}

int check_format(WAVHEADER *header)
{
    if (memcmp(header->format, "WAVE", 4) != 0)
    {
        return 0;
    }
    // TODO #4
    return 1;
}

int get_block_size(WAVHEADER *header)
{
    // TODO #7
    int num_channels = header->numChannels;
    int bytes_samples = header->bitsPerSample / 8;
    return num_channels * bytes_samples;
}