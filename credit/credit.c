#include <cs50.h>
#include <stdio.h>

long prompt_card(void);
int length(long x);
int check_digits(long x);
int main(void)
{
    long card = prompt_card();
    printf("Card Number: %li\n", card);
    int card_length = length(card);
    printf("Card Length: %i\n", card_length);
    int first_set = check_digits(card);
    printf("First Set: %i\n",first_set);
}


long prompt_card(void)
{
    long card;
    do
    {
        card = get_long("Enter your credit card number: ");
    }
    while (card < 1);
    return card;
}

int length(long x)
{
    int counter = 0;
    while (x > 0)
    {
        x= x / 10;
        counter++;
    }
    return counter;
}

int check_digits(long x)
{
    int first_set=0;
    int digits=0;
    while(x>0)
    {
        digits = x%10;
        printf("%d",digits);
        x = x/10;
        if(digits*2 > 9)
        {
            int counter;
            while (digits > 0)
            {

            }
        }
    }
    return first_set
}

