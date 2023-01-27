#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int ascii_alphabet[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    printf("Score 1 : %d\n", score1);
    printf("Score 2 : %d\n", score2);
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
    printf("\n");
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    // Initialize variables
    int index = 0, ascii = 0, score = 0 ;
    // Loop through each letter of the word , then conver it
    // to upper case.
    for (int i = 0 ; i < strlen(word) ; i++)
    {
        word[i] = toupper(word[i]);
        // Conver the upper case letter to ascii, since ascii
        // variable is an integer.
        ascii = word[i];
        // Loop throught the ascii_alphabet and match the
        // found letter with the index from the ascii alphabet
        for (int j = 0 ; j < 26 ; j++)
        {
            if (ascii_alphabet[j] == ascii)
            {
                // If there's a match, make index variable = to
                // index of the letter from the alphabet, then increment
                // the score variable by the index of the POINTS array.
                index = j ;
                score += POINTS[index];
                index = 0;
            }
        }
    }
    return score;
}


