// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int upper = 0, lower = 0, number = 0, symbol = 0;
    for (int i = 0 ; i < strlen(password) ; i++)
    {
        if (isalpha(password[i]))
        {
            if (password[i] == tolower(password[i]))
            {
                lower++;
            }
            else if (password[i] == toupper(password[i]))
            {
                upper++;
            }
        }
        else if (isdigit(password[i]))
        {
            number++;
        }
        else
        {
            symbol++;
        }
    }
    if (upper >= 1 && lower >= 1 && number >= 1 && symbol >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
