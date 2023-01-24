#include <cs50.h>
#include <stdio.h>

long prompt_card(void);
int length(long x);
int first_sum(long x);
int second_sum(long x);
int first_digits (long x);


int main(void)
{
    long card = prompt_card();
    // printf("Card Number: %li\n", card);
    int card_length = length(card);
    // printf("Card Length: %i\n", card_length);
    int check_sum = first_sum(card)+second_sum(card);
    printf("Final Sum = %i\n",check_sum);
    int first_dg = first_digits(card);
    // printf("First digits: %i\n",first_dg);

    if (check_sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    if ((first_dg /10 == 5) && (0 < first_dg % 10 && first_dg % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((first_dg / 10 == 3) && (first_dg % 10 == 4 || first_dg % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (first_dg / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
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

int first_sum(long x)
{   int sum = 0;
    int num1 = 0;
    int num2 = 0;
    for (int i = 0 ; i < x ; i++)
    {
        num1 = (x/10)%10;
        num1*=2;
        if(num1 >= 10)
        {
            num1 = (num1%10+ num1/10);
            sum+=num1;
        }
        else
        {
            sum+=num1;
        }
        num1 = 0;
        x/=100;
    }

    printf("\n");
    printf("First Sum = %i\n",sum);
    return sum;
}

int second_sum(long x)
{
    int num = 0;
    int sum = 0;
    for  (int i = 0;i<x;i++)
    {
        num = x%10;
        sum+=num;
        x/=100;
    }
    printf("Second Sum = %i \n", sum);
    return sum;

}

int first_digits (long x)
{
    int digits = 0;
    while (x > 100)
    {
    digits = x/=10;
    }
    printf("First Digits: \n",digits)
    return digits;
}