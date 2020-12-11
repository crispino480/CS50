 #include "helpers.h"
 #include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg;
    int j=0;
    
    for (int i = 0 , n = height; i < n; i++)
    {
       do
         {
          // get the rgb pixel of the image, compute the average and assign the avg  value as new value to r,g,b
         
          avg = round((image[i][j].rgbtRed +  image[i][j].rgbtGreen +  image[i][j].rgbtBlue)/3);
          image[i][j].rgbtRed =avg;
          image[i][j].rgbtGreen =avg;
          image[i][j].rgbtBlue =avg;
           
         
        j++;

         } while (j < width);

    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
