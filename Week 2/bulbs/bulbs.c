#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;


void print_bulb(int bit);
void to_binary(string word);

int main(void)
{
    // TODO
    string input = get_string("Input: ");
    to_binary(input);
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
    //initialize an ascii variable that equals to the ascii format
    // of a letter
    // initialize a binary variable that can be equal to either
    // 1 or 2
    int ascii = 0;
    int binary = 0;
    //Convert each letter to its ascii format by looping through
    //each letter
    for (int i = 0 ; i < strlen(word) ; i++)
    {
        ascii = word[i];
        // make a loop that runs from 2^7 to 2^0 (the bits allocated)
        // for each letter
        for (int j = 7 ; j >= 0 ; j --)
        {
            //Make a greedy algorithm where you compare if the
            //ascii letter with the bits allocated.
            int bits = pow(2, j);
            // if the ascii letter is equal to the number of bits
            // the binary variable becomes 1.
            // Don't forget to get the remainder of the ascii % bits
            // This becomes the new ascii variable
            if (ascii == bits)
            {
                binary = 1;
                ascii %= bits;
            }
            // If ascii variable is lower than bits , assign the
            // binary variable to 0
            else if (ascii < bits)
            {
                binary = 0 ;
            }
            else
            {
                // if the ascii variable is equal to the number
                // of bits, assign the binary variable to 1 and
                // get the remainder of ascii % bits.
                //
                binary = 1 ;
                ascii %= bits;
            }
            // Once you get the binary variable equal to either
            // 1 or 0, use the print_bulb function and pass
            // the binary variable as its argument.
            print_bulb(binary);
        }
        printf("\n");
    }
}
