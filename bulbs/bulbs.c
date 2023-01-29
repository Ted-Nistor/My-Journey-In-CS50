#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;


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
        for (int j = 7 ; j >= 0 ; j --)
        {
            int bits = pow(2, j);
            if (ascii == bits)
            {
                printf("1");
            }
            else if (ascii < bits)
            {
                printf("0");
            }
            else
            {
                printf("1");
                ascii %= bits;
            }
        }
    }
    printf("\n");
}
