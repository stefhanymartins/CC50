#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int countingLetters(string text);
int countingWords(string text);
int countingSentences(string text);

int main(void)
{
    //prompt user
    string text = get_string("Text: ");

    //Calculation
    float L = ((float)countingLetters(text) / (float)countingWords(text)) * 100;
    float s = ((float)countingSentences((text)) / (float)countingWords(text)) * 100;
    float subIndex = 0.0588 * L - 0.296 * s - 15.8;

    int index = round(subIndex);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int countingLetters(string text)
{
    //string length
    int i = strlen(text);
    int letters = 0;

    for (int j = 0; j < i; j++)
    {
        //counting letters
        char c = text[j];
        if (isalpha(c) != 0)
        {
            letters++;
        }
    }
    return letters;
}

int countingWords(string text)
{
    //string length
    int i = strlen(text);
    int words = 0;

    for (int j = 0; j < i; j++)
    {
        char c = text[j];
        //counting words
        if (c == ' ')
        {
            words++;
        }
    }
    //to account for last word
    words = words + 1;
    return words;
}

int countingSentences(string text)
{
    //string length
    int i = strlen(text);
    int sentences = 0;

    for (int j = 0; j < i; j++)
    {
        char c = text[j];
        //countig sentences
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }
    return sentences;
}