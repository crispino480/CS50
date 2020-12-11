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
       
          // get the rgb pixel of the image, use a formula to change each pixel on the image
         for (int j = 0 , m = width; j < m; j++)
             {
                 
                 
               int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
               int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
               int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
               
               if(sepiaRed >255)
               {
                sepiaRed =255;
               }
               if(sepiaGreen >255)
               {
                sepiaGreen =255;
               }
               if(sepiaBlue >255)
               {
               sepiaBlue =255;
               }
               
                 image[i][j].rgbtRed = sepiaRed;
                 image[i][j].rgbtGreen = sepiaGreen;
                 image[i][j].rgbtBlue = sepiaBlue;
               
             }
                  
                  
         } 
    

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
     for (int i = 0 , n = height; i < n; i++)
    {
       //int tmp;
          // get the rgb pixel of the image, compute the average and assign the avg  value as new value to r,g,b
         for (int j = 0 , m = width; j < m; j++)
             {
               // hold the value of each pixel 
               int tmp1 = image[i][j].rgbtRed;
               int tmp2 = image[i][j].rgbtGreen;
               int tmp3 = image[i][j].rgbtBlue;
               
                image[i][j].rgbtRed = image[i][m-1-j].rgbtRed;
                image[i][j].rgbtGreen = image[i][m-1-j].rgbtGreen;
                image[i][j].rgbtBlue = image[i][m-1-j].rgbtBlue;
                
                image[i][m-1-j].rgbtRed = tmp1;
                image[i][m-1-j].rgbtGreen = tmp2;
                image[i][m-1-j].rgbtBlue = tmp3;

                
             }
             
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
