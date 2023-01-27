#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string paragraph);
int count_words(string paragraph);
int count_sentences(string paragraph);

int main(void)
{
    // get string input from the user and print it.

    string paragraph = get_string("Text: ");
    printf("%s\n", paragraph);
    printf("%i letters\n", count_letters(paragraph));
    printf("%i words\n", count_words(paragraph));
    printf("%i sentences\n", count_sentences(paragraph));


}

// make a letter counter by incrementing the counter if
//the character is alphabetical
int count_letters(string paragraph)
{
    int letters = 0;
    for (int i = 0 ; i < strlen(paragraph) ; i++)
    {
        if (isalpha(paragraph[i]))
        {
            letters++;
        }
    }
    return letters;
}

//initialize a word counter while the index of the paragraph is less than the length of the paragraph
int count_words(string paragraph)
{
    int words = 0;
    int i = 0;
    do
    // (if the character is a space) or (if the next character is a '\0' and the current character is not a space),
    // increase the words counter by 1.
        {
            if (isspace(paragraph[i]) || (paragraph[i+1] == '\0' &&  !isspace(paragraph[i])))
            {
                words++;
            }
        i++;
        }
    while (i < strlen(paragraph));
    return words;
}

//initialize a sentence counter and increment it by 1 whenever the index of the paragraph is == '.' or '?' or '!'.
int count_sentences(string paragraph)
{
    int sentences = 0;
    int i = 0;
    do
    {
        if (paragraph[i] == '.' || paragraph[i] == '!' || paragraph[i] == '?')
        {
            sentences++;
        }
    }
    while (i < strlen(paragraph));
    return sentences;
}