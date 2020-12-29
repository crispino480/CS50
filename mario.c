/*Let’s recreate those pyramids in C, albeit in text, 
using hashes (#) for bricks, a la the below. Each hash is a bit taller 
than it is wide, so the pyramids themselves are also be taller than they are wide.

   #  #
  ##  ##
 ###  ###
####  ####


*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
//prompt for a number for the pyramid height

    int height;


    do
    {
        printf("How tall is your pyramid\n");
        height = get_int("height: ");

    }
    while (height < 1 || height > 8);
    // The input value is check to meet the requirement, otherwise the user must enter a value again

// print the left side of the pyramid
    for (int i = 1 ; i <= height ; i++)
    {
        for (int j = 1 ; j <= height ; j++)
        {
            if (j > height - i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        // allocate a space between the two pyramid
        printf("  ");
        //build the right side of the pyramid
        for (int k = 1 ; k <= height ; k++)
        {
            if (i < k)
            {
                printf("");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }

}