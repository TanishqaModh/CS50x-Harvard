#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    // Prompt the user for text input.
    string text = get_string("Text: ");
    // Initialise counters.
    int letters = 0;
    int words = 1; // Starts from 1 assuming atleast one word
    int sentences = 0;
    // Loop through eah character in text
    for (int i = 0; i < strlen(text); i++)
    {
        // count alphabetic characters as 1 letter
        if (isalpha(text[i]))
        {
            letters++;
        }
        // count spaces to estimate number of words
        else if (text[i] == ' ')
        {
            words++;
        }
        // count sentence ending punctuation marks
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    // Calculate average per 100 words
    float L = (letters / (float) words) * 100;   // Average per 100 words
    float S = (sentences / (float) words) * 100; // Average sentence per 100 words
    // Coleman-Liau index formula
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // Round to nearest whole number
    int grade = round(index);
    // Output the grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
