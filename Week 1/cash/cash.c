#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();
    printf("Cents: %i\n", cents);

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    //Prompt the user for the number of cents
    int cents;
    do
    {
        cents = get_int("Input cents: ");
    }
    while (cents < 1);
    return cents;

}

int calculate_quarters(int cents)
{
    // Make an if else statements so that if the number of cents = 25 , return 1 quarter, else return cent/25 quarters
    if (cents == 25)
    {
        return 1;
    }
    else
    {
        return cents / 25;
    }
}

int calculate_dimes(int cents)
{
    //Make an if else statement so that if the number of cents = 10, return 1 dime, else return cent/10 dimes
    if (cents == 10)
    {
        return 1;
    }
    else
    {
        return cents / 10 ;
    }
}

int calculate_nickels(int cents)
{
    //Make an if else statement so that if the number of cents = 5, return 1 nickel, else return cent/5 nickels
    if (cents == 5)
    {
        return 1;
    }
    else
    {
        return cents / 5 ;
    }
}

int calculate_pennies(int cents)
{
    //Make an if else statement so that if the number of cents = 1, return 1 penny, else return cents = nickels
    if (cents == 5)
    {
        return 1;
    }
    else
    {
        return cents;
    }
}
