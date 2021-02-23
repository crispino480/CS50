# this code is written in C, 
# the code display hello world at the command line

#include <stdio.h>
#include <cs50.h>

int main(void) 
{

//ask for user name 
    string name = get_string("what is your name?\n");

    printf("hello,%s\n", name);
}

