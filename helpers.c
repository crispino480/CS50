 #include "helpers.h"
 #include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    
    for (int i = 0 , n = height; i < n; i++)
    {
       
          // get the rgb pixel of the image, compute the average and assign the avg  value as new value to r,g,b
         for (int j = 0 , m = width; j < m; j++)
             {
              avg = round((image[i][j].rgbtRed +  image[i][j].rgbtGreen +  image[i][j].rgbtBlue)/3.00);
              image[i][j].rgbtRed =avg;
              image[i][j].rgbtGreen =avg;
              image[i][j].rgbtBlue =avg;
         } 
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    
    for (int i = 0 , n = height; i < n; i++)
    {
       
          // get the rgb pixel of the image, compute the average and assign the avg  value as new value to r,g,b
         for (int j = 0 , m = width; j < m; j++)
             {
                 
                 
               int sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtRed + .189 * image[i][j].rgbtRed;
               int sepiaGreen = .349 * image[i][j].rgbtGreen + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtGreen;
               int sepiaBlue = .272 * image[i][j].rgbtBlue + .534 * image[i][j].rgbtBlue + .131 * image[i][j].rgbtBlue;
               
               if(sepiaRed >255)
               {
                image[i][j].rgbtRed =255;
               }else if(sepiaGreen >255)
               {
                image[i][j].rgbtGreen =255;
               }else if(sepiaBlue >255)
               {
               image[i][j].rgbtBlue =255;
               }else 
               {
                 image[i][j].rgbtRed = sepiaRed;
                 image[i][j].rgbtGreen = sepiaGreen;
                 image[i][j].rgbtBlue = sepiaBlue;
               }
             }
                  
                  
         } 
    

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