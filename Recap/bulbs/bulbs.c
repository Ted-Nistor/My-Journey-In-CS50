#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;
void print_bulb(int bit);
void to_binary(string word);

int main(void)
{
    string word = get_string("Word: ");
    to_binary(word);
    printf("\n");
    // TODO
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
void to_binary(string word)
{
    int binary, bits;
    for (int i = 0; i < strlen(word); i++)
    {
        int temp = word[i];
        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {
            bits = pow(2, j);
            if (temp >= bits)
            {
                binary = 1;
                temp %= bits;
            }
            else
            {
                binary = 0;
            }
            print_bulb(binary);
        }
        printf("\n"); // Move this line inside the outer loop
    }

}