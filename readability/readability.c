#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


float count_letters(string paragraph);
float count_words(string paragraph);
float count_sentences(string paragraph);

int main(void)
{
    // get string input from the user and print it.

    string paragraph = get_string("Text: ");
    float index;
    float letters = count_letters(paragraph);
    float words = count_words(paragraph);
    float sentences = count_sentences(paragraph);
    printf("%s\n", paragraph);
    printf("%f letters\n", count_letters(paragraph));
    printf("%f words\n", count_words(paragraph));
    printf("%f sentences\n", count_sentences(paragraph));
    index = ((letters / words) * 100) * 0.0588 - 0.296 * ((sentences / words) * 100) - 15.8;
    printf("Grade %i\n", (int)index);



}

// make a letter counter by incrementing the counter if
//the character is alphabetical
float count_letters(string paragraph)
{
    float letters = 0;
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
float count_words(string paragraph)
{
    float words = 0;
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
float count_sentences(string paragraph)
{
    float sentences = 0;
    int i = 0;
    while (i < strlen(paragraph))
    {
        if (paragraph[i] == '.' || paragraph[i] == '!' || paragraph[i] == '?')
        {
            sentences++;
        }
        i++;
    }
    return sentences;
}