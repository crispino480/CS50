# This program  is written in C
# Caesar used to “encrypt onfidential messages by shifting each letter therein by some number of places. 
# For instance, he might write A as B, B as C, C as D, …, and, wrapping around alphabetically, Z as A. 
# And so, to say HELLO to someone, Caesar might write IFMMP.  Upon receiving such messages from Caesar, 
# recipients would have to “decrypt” them by shifting letters in the opposite direction by the same number of places.
# This program encrypt message, output fromt the command line:
#
#     $ ./caesar 13
#     plaintext:  hello, world
#     ciphertext: uryyb, jbeyq


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cs50.h>
#include <ctype.h>


int main (int argc, string argv[])
{

// check for arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {

        for (int i = 0, n = strlen(argv[1]); i < n; i++)
           {
            if (!(isdigit(argv[1][i]))) // This Iterate over the provided argument to make sure all characters are digits
            {
                printf("Usage: ./caesar key\n");
                i = n;
                return 1;
            }
        }

    }


    int k = atoi(argv[1]);
    string t = get_string("Plaintext:");


    printf("ciphertext: ");

    for (int j = 0 ; j < strlen(t); j++)
    {

        if (isalpha(t[j]))
        {

            if (islower(t[j]))
            {

                printf("%c",( ((t[j] - 97) + k) % 26 + 97));
            }
            else
            {
                printf("%c",( ((t[j] - 65) + k) % 26 + 65));
            }

        }
        else
        {
            printf("%c", t[j]);
        }
    }

    printf("\n");

    return 0;
}
