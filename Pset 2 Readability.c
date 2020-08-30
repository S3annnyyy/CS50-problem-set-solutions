#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{
    //counting letters
    string text = get_string("Text: ");
    int k = strlen(text);                          //getting length of text in int
    float letters_count = 0;
    for (int i = 0; i < k; i++)                    //for loop to count no.of letters
    {
        if (isalpha(text[i]))
        {
            letters_count++;
        }
    }

    //counting no.of words
    float word_count = 0;
    for (int w = 0; w < k; w++)
    {
        if(text[w] == ' ')
        {
            word_count++;
        }
    }
     word_count++;

    //counting no. of sentences
    float sentence_count = 0;
    for (int y = 0; y <k; y++)
    {
        if (text[y] == '!' || text[y] == '.' || text[y] == '?')
        {
            sentence_count++;
        }
    }

    //finding L and S that is part of Coleman-Liau index
    float L = (letters_count/word_count) * 100;
    float S = (sentence_count/word_count) * 100;
    float index = 0.0588 * L -0.296 * S -15.8;
    int grade_number = round(index);

    if (grade_number > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade_number < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade_number);
    }
}
