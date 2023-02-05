#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
// Prototype
int grade(float L, float S);

// Main
int main(void)
{
    string text = get_string("Text: ");
    int s = strlen(text);
    //char newText;
    int letters = 0;
    int words = 0;
    int sentences = 0;


    // Counting the numbers of Letter it have.
    for (int i = 0; i < s; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letters++;
        }
    }

    // Conting the numbers of words.
    for (int i = 0; i < s; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    words++;

    // Counting the numbers of sentences.
    for (int i = 0; i < s; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    
    // Seting the function's variables
    float L = (letters * 100) / (float) words;
    float S = (sentences * 100) / (float) words;
    
    // this function will define what is the phrases grade.
    int g = grade(L, S);
    
    // Grade print
    if (g < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (g > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", g);
    }
}


// Functions
int grade(float L, float S)
{
    int g2 = 0;
    float g = (0.0588 * L) - (0.296 * S) - 15.8;
    g2 = g;
    float r = g - g2;
    if (r >= 0.5)
    {
        g2++;
    }
    return g2;
}