#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int ascii_alphabet[] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};

int compute_score(string word);
int string_to_ascii (string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int ascii1 = string_to_ascii(word1);
    int ascii2 = string_to_ascii(word2);
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
}

int compute_score(int ascii_word)
{
    // TODO: Compute and return score for string
    int score = 0;
    int index = 0;
    while (ascii_word >= 0)
    {
        //Use a module%100 to get the last two digits from the ascii_word
        index = ascii_word % 100 ;
        //Loop throught the ascii alphabet to match last two digits with an ascii letter from the alphabet
        for (int i = 0 ; i < 26 ; i++)
        {
            if (ascii_alphabet[i] == index)
            {
        //If there's a match, store the index of the letter into the index variable, then use that variable to
        // access the value from the POINTS array. Increment the score by the value of the points array.
                index = i;
                score+= POINTS[index];
                index = 0;
            }
        }
        // Remove the last two digits from the asciiword.
        ascii_word/100;
    }
    return score;
}

int string_to_ascii (string word)
{
    // initialize variable that will become = to string converted into ascii
    int ascii;
    // convert each letter to upper case.
    for (int i = 0 ; i < strlen(word) ; i ++)
    {
        word[i] = toupper(word[i]);
    }
    // convert each uppercase letter to ascii (they will be without space)
    for (int j = 0 ; j < strlen(word); j ++)
    {
        ascii = printf("%d", word[j]);
    }
    return ascii;
}