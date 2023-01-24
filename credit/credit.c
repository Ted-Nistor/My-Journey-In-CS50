#include <cs50.h>
#include <stdio.h>

long prompt_card(void);
int length(long x);
int first_sum(long x);
int second_sum(long x);
// void check_sum (int first_sum(long x),int second_sum(long x));

int main(void)
{
    long card = prompt_card();
    printf("Card Number: %li\n", card);
    int card_length = length(card);
    printf("Card Length: %i\n", card_length);
    // int check = first_sum(card)+second_sum(card);
    // printf("Final Sum = %i\n",check);
    // check_sum(first_sum(card),second_sum(card));
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

void check_sum (first_sum(long x),second_sum(long x))
{
    int final_sum = first_sum(long x) + second_sum(long x)
    printf("Final Sum = %i\n",final_sum);
}

