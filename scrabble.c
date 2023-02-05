#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    //printf("%i\n", score1);
    int score2 = compute_score(word2);
    //printf("%i\n", score2);

    // TODO: Print the winner
    if(score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if(score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else if(score1 == score2)
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int n = strlen(word);
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        int r = 0;
        int isUpper = isupper(word[i]);
        //printf("%i\n", isUpper);
        int isAlpha = isalpha(word[i]);
        //printf ("%i\n", isAlpha);
        if(isUpper != 0 && isAlpha > 0)
        {
            int p = word[i] - 65;
            r = POINTS[p];
        }
        else if(isUpper == 0 && isAlpha > 0)
        {
            int p = word[i] - 97;
            r = POINTS[p];
        }
        s = s + r;
    }
    return s;
}