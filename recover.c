#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{


//Ensure user run program with two words at prompt
    if (argc != 2)
    {
        fprintf(stderr, "Usage:  %s image\n", argv[0]);
        return 1;
    }

//open file
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Unable to open file%s\n", argv[1]);
        return 1;
    }

//read 3 bytes from file
    BYTE buffer[512];
              fread(buffer, 512, 1, file);

    char *filename = malloc(sizeof(int) * 3);
            int count =  0;
         FILE *img;

//check if bytes are 0xff 0xd8 0xff
    while (fread(buffer, sizeof(BYTE), 1, file) > 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg" , count);
            img = fopen(filename, "w");
            fwrite(&buffer, sizeof(BYTE), 1,img);
            fclose(img);
            count++;
        }
    }


    free(filename);
    fclose(file);
    return 0;
}




