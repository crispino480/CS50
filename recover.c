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
return 1;
}

BYTE buffer[512];
char* file_name = malloc(sizeof(int)*3);
int count = 0;
FILE* outptr =NULL;


while(fread(buffer,1, 512,inputptr) == 512)
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            if(outptr!=NULL)
            {
                fclose(outptr);
            }
            
                sprintf(file_name, "%03i.jpg", count);
                outptr = fopen(file_name, "w");
                
                if(outptr!=NULL)
                {
                fwrite(buffer, 1, 512, outptr);
                fclose(outptr);
                }
                
                
        }
}

    free(file_name);
    fclose(inputptr);
    fclose(outptr);
   
return 0;
}