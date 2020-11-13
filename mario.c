// this version of Mario if feeling less comfortable

#include <stdio.h>
#include <cs50.h>

int main(void){
//prompt for a number for the pyramid height

    int height;

  do {

printf("How tall is your pyramid\n");
        height = get_int("height: ");

    }while(height < 1 || height > 8);


/*
 for (int i = 1 ; i <= height ; i++)
    {
    for (int j = 1 ; j <= height ; j++){
        if(j > height - i) {
      printf("#");
        }else{
        printf(" ");
         }
    }
    printf("  ");
     for (int k = 1 ; k <= height ; k++){
      if( i < k) {
    printf(" ");
        }else {
    printf("#");
         }
       }
     printf("\n");
}*/

for (int i = 1 ; i <= height ; i++)
   {
    for (int j = 1 ; j <= height ; j++)
    {
      if(j > height - i) {
      printf("#");
        }else{
    printf(" ");
         }
    }
    printf("\n");
  }
}

