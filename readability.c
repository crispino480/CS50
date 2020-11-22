#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

string userInput();
int lettercount(string t);
int wordcount(string t);
int sentencecount(string t);
int countl = 0;
int countw = 0;
int counts = 0;
string space = " ";

 
int main(void)
{

string s = userInput(); //To get user input
float lt = (float)lettercount(s);
float w = (float)wordcount(s);
float st = (float)sentencecount(s);

//index = 0.0588 * L - 0.296 * S - 15.8
float L = (lt*100/w);
float S = (st*100/w);

int index = round(0.0588*L - 0.296*S - 15.8);

if(index < 1)
{ 
 printf(" Before Grade 1\n");
}else if (index >= 16)
{
printf(" Grade 16+\n");
}else
{
  printf(" Grade %i\n",index);
}

}







//this function count the number of sentences in a text
int sentencecount(string t)
{
  int n = strlen(t);
for(int i = 0; i < n; i++)
    {
      if( t[i] == '.' || t[i] == '!' || t[i] == '?')
        {
            
         counts++;// count letters
        }
    }
    return counts;
}



//this function count the number of words in a sentence
int wordcount(string t)
{
  int n = strlen(t);

  for(int i=0; i<n;i++)
    {
       if (t[i] == ' ')
        {
            countw++;// count letters
        }
    }
    return (countw + 1);
}



//this function count the number of letters in a sentence
int lettercount(string t)
{
int n = strlen(t);

  for(int i=0; i < n; i++)
    {
         if (isalpha(t[i])) // check if the input is a letter
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

 