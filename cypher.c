#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

//Main
int main(int argc, string argv[])
{

    if(argc == 2)
    {
        // Geting how was the string lenght
        int n = strlen(argv[1]);

        // Creating some variables
        bool error;
        int key;

        //Certify if do not have a letter in the key using a "for" loop.
        for(int i = 0; i < n; i++)
        {
            if((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
            {
                error = true;
            }
        }
        if(error == true)
        {

        }
        // Cipher code is here
        key = atoi(argv[1]);
        if(key < 1)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        if(error != true)
        {
            string plaintext = get_string("Plaintaxt: ");

            n = strlen(plaintext);

            printf("Ciphertext: ");
            for(int i = 0; i < n; i++)
            {
                if(isalpha(plaintext[i]) != 0 && isupper(plaintext[i]))
                {
                    char c = (plaintext[i] + key) - 65;
                    c = (c % 26) + 65;

                    printf("%c", c);
                }
                else if(isalpha(plaintext[i]) == 0)
                {
                    printf("%c", plaintext[i]);
                }
                else if(isalpha(plaintext[i]) != 0 && islower(plaintext[i]))
                {
                    char c = (plaintext[i] + key) - 97;
                    c = (c % 26) + 97;

                    printf("%c", c);
                }

            }
            printf("\n");
            return 0;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}