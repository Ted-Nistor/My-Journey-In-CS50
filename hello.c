#include <cs50.h>
#include <stdio.h>


int main(void){
    printf("hello,world! \n");
    string first = get_string("What's your first name? ");
    string last = get_string("What's your last name? ");
    printf("hello, %s %s\n",first,last);
    char name = fgetc("What's your nickname? ");
    printf("hello, %s!\n",name);
}


