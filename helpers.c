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

          // get the rgb pixel of the image, compute the average and assign the avg  value as new value to r,g,b
         for (int j = 0 , m = width; j < m/2; j++)
             {
               // hold the value of each pixel
               int tmp1 = image[i][j].rgbtRed;
               int tmp2 = image[i][j].rgbtGreen;
               int tmp3 = image[i][j].rgbtBlue;

                image[i][j].rgbtRed = image[i][m-j-1].rgbtRed;
                image[i][j].rgbtGreen = image[i][m-j-1].rgbtGreen;
                image[i][j].rgbtBlue = image[i][m-j-1].rgbtBlue;

                image[i][m-j-1].rgbtRed = tmp1;
                image[i][m-j-1].rgbtGreen = tmp2;
                image[i][m-j-1].rgbtBlue = tmp3;
             }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
 RGBTRIPLE tmp[height][width];

 for (int i = 0 , n = height; i < n; i++)
    {
          // get the rgb pixel of the image,
         for (int j = 0 , m = width; j < m/2; j++)
      {

       int redSum=0;
       int greenSum=0;
       int blueSum=0;
       int divider=0;

if(i != 0 && j !=0)
{

for(int r=-1; r<2;r++)
  {
   for(int s=-1; s<2;s++)
   {

    redSum+=image[i+r][j+s].rgbtRed;
    greenSum +=image[i+r][j+s].rgbtGreen;
    blueSum += image[i+r][j+s].rgbtBlue;
    divider++;
    }
   }
  }


 if(i == 0 || j == 0)
 {

 if(i == 0 && j ==0 )
 {
  for(int r=0; r<2;r++)
   {
    for(int s=0; s<2;s++)
    {
     redSum+=image[r][s].rgbtRed;
     greenSum +=image[r][s].rgbtGreen;
     blueSum += image[r][s].rgbtBlue;
     divider++;
     }
   }

  }else if (i == 0 && j != 0)
{
for(int r=0; r<2;r++)
   {
    for(int s=-1; s<2;s++)
    {

redSum+=image[r][j+s].rgbtRed;
greenSum +=image[r][j+s].rgbtGreen;
blueSum += image[r][j+s].rgbtBlue;
divider++;
}
}

}else if(i != 0 && j == 0)
{
for(int r=-1; r<2;r++)
   {
    for(int s=0; s<2;s++)
    {

redSum+=image[i+r][j].rgbtRed;
greenSum +=image[i+r][j].rgbtGreen;
blueSum += image[i+r][j].rgbtBlue;
divider++;
}

}

}

tmp[i][j].rgbtRed=round(redSum/divider);
tmp[i][j].rgbtGreen=round(greenSum/divider);
tmp[i][j].rgbtBlue=round(blueSum/divider);

for (int ii = 0 , nn = height; ii < nn; ii++)
    {

          // get the rgb pixel of the image, 
         for (int jj = 0 , mm = width; jj < mm; jj++)
             {
              image[ii][jj].rgbtRed = tmp[i][j].rgbtRed;
              image[ii][jj].rgbtGreen = tmp[i][j].rgbtGreen;
              image[ii][jj].rgbtBlue = tmp[i][j].rgbtBlue;
         }
    }

    return;
}
}
}
}
