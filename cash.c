#include <cs50.h>
#include <stdio.h>
#include <math.h>

float userinput(); // this function valid the user input, the entry must be >0
int changeCount(int c);// this function described below

int main(void)
{


 float dollars = userinput();

int cents = round(dollars * 100);
int r = changeCount(cents);

printf("%i\n",r);
}







float userinput()
{
    float valueInput;
    do
    {
     valueInput = get_float("your change : ");

    }while(valueInput < 0);

 return valueInput;
}

// this function add the quotients together, then use the remaining as new value to divid by 10, then 5 and 1
int changeCount(int c){

int cc = c/25 + (c % 25)/10 + ((c % 25)%10)/5 + ((c % 25)%10)%5/1;

 return cc;
}