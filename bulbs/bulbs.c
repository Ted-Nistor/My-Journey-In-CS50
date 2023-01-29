#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
const int bits[] = {1, 2, 4, 8, 16, 32, 64, 128};

void print_bulb(int bit);
void to_decimal(string word);

int main(void)
{
    // TODO
    string input = get_string("Input: ");
    to_decimal(input);
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

void to_decimal(string word)
{
    int ascii = 0;
    for (int i = 0 ; i < strlen(word) ; i++)
    {
        ascii = word[i];
        printf("%i, ",ascii);
    }
    printf("\n");
}
