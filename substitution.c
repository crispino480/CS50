/* In a substitution cipher, we “encrypt” a message by replacing every letter with another letter.
To do so, we usea key: in this case, a mapping of each of the letters of the alphabet to the letter
it should correspond to when we encrypt it. To “decrypt” the message, the receiver of the message
would need to know the key, so that they can reverse the process:translating the encrypt text
back into the original message .
*/

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
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if(strlen(argv[1])!=26 )
    {

     printf("Key must contain 26 characters.\n");
        return 1;


    } else {


        for (int i = 0, n = strlen(argv[1]); i < n; i++)
          {
            if (isalpha(argv[1][i])) // This Iterate over the provided argument to make sure all characters are alphabethic
            {
               for(int r = 1, m = strlen(argv[1]); r < m; r++)
               {
                   if( argv[1][i] == argv[1][r] ){
                      printf("Key must not content repeat character\n");
                       r=m;
                      
                       return 1;
                   }
                    i=n;
               }


            }else {

                printf("Usage: ./substitution key\n");
                i = n;
                return 1;
          }


    }

    }

    int k = 0;
    string t = get_string("Plaintext:");


    printf("ciphertext:");

    for (int j = 0 ; j < strlen(t); j++)
    {

        if (islower(t[j]))
        {
        printf("%c", tolower(argv[1][t[j] - 'a']));
        }else if(isupper(t[j]))
        {
        printf("%c", toupper(argv[1][t[j] - 'A']));

        }else{
           printf("%c", t[j]);
        }


    }

    printf("\n");

    return 0;
}


