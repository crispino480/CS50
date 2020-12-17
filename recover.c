#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;



int main(int argc, char *argv[])
{

if(argc !=2)
{
 fprintf(stderr, "Usage: %s image\n",argv[0]);
 return 1;
}

FILE *inputptr = fopen(argv[1], "r");

if(inputptr==NULL)
{
fprintf(stderr, "Unable to open file%s\n", argv[0]);
return 2;
}

BYTE buffer[512];
char file_name[8];
int count = 1;
FILE* outptr =NULL;
int isFound =0;

//while(fread(buffer,512, 1,inputptr) == 1)
while( fread(buffer, sizeof(buffer), 1, inputptr) ||feof(inputptr)==0) // Read blocks of 512 bytes, one at a time
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(isFound==1)
            {
                fclose(outptr);
            }else
            {
               isFound=1; 
            }

                sprintf(file_name, "%03i.jpg", count);
                outptr = fopen(file_name, "w");
                count++;
                
                if(outptr!=NULL)
                {
                fwrite(&buffer, sizeof(buffer), 1, outptr);
                
                }
        }
}

   fclose(inputptr);
  // fclose(outptr);
 
return 0;
}