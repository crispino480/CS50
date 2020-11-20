#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

 string userInput();
 int lettercount(string t);
 int wordcount(string t);
 int countl=0;
 int countw=0;
 char space = 0;


int main (void)
{

string s = userInput(); //To get user input

printf("%i letter (s) \n",lettercount(s));
printf("%i words (s) \n",wordcount(s));
}




//this function count the number of letters in a sentence


int wordcount(string t)
{
  int n = strlen(t);

  for(int i=0; i<n;i++)
    {
      if(!((t[i] >= 'a' && t[i] <= 'z' ) || (t[i] >= 'A' && t[i] <= 'Z'))  ) //check input non words
      {
       countw++; // count words
      }

    }
    return countw;
}



int lettercount(string t)
{
int n = strlen(t);

  for(int i=0; i<n;i++)
    {
      if ( (t[i] >= 'a' && t[i] <= 'z' ) || (t[i] >= 'A' && t[i] <= 'Z')) // check if the input is a letter
        {
           countl++;// count letters
         }
     }
     return countl;
 }


//function to prompt for user input, return its value
string userInput()
{
  string s = get_string (" Enter your text:\n");
    return s;

}

