#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc == 2)
    {
        int n = strlen(argv[1]);
        // Checking the Key
        int c = 0;
        if(n != 26)
        {
            printf("The Key must contain 26 characters \n");
            return 1;
        }


        for(int i =0; i < n; i++)
        {
            int isLower = islower(argv[1][i]);
            int isAlpha = isalpha(argv[1][i]);
            if(isAlpha == 0)
            {
                printf("Invalid Character in the key \n");
                return 1;
            }
            if(isLower != true)
            {
               argv[1][i] = toupper(argv[1][i]);
            }
            for(int z=0; z < n; z++)
            {
               if(argv[1][i] == argv[1][z])
                {
                    c++;
                }
                if(c > 26)
                {
                    printf("Usage: ./caesar key\n");
                    return 1;
                }
            }
        }
        string plaintext = get_string("Plaintext: ");
        n = strlen(plaintext);
        //Cipher the code
        printf("ciphertext: ");
        for(int i = 0; i < n; i++)
        {
            int isLower = islower(plaintext[i]);
            int isUpper = isupper(plaintext[i]);
            int isAlpha = isalpha(plaintext[i]);
            if(isAlpha != 0 && isLower != 0)
            {
                int k = plaintext[i];
                k = k - 97;
                char q = argv[1][k];
                q = tolower(q);
                printf("%c", q);
            }
            else if(isAlpha != 0 && isUpper != 0)
            {
                int k = plaintext[i];
                k = k - 65;
                char q = argv[1][k];
                q = toupper(q);
                printf("%c", q);
            }
            else if(isAlpha != 1)
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;


    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}