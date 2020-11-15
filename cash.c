#include <cs50.h>
#include <stdio.h>
#include <math.h>

float userinput();
int changeCount(int c);

int main(void)
{


 float dollars = userinput();

int cents = round(dollars * 100);
int r = changeCount(cents);

printf ("%i\n",r );
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


int changeCount(int c){

int cc = c/25 + (c % 25)/10 + ((c % 25)%10)/5 + ((c % 25)%10)%5/1;

 return cc;
}