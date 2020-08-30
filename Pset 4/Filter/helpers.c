#include "helpers.h"
#include <math.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int r;
    int b;
    int g;
    int average_pixel_value;
    // using for loop to convert each row and column
    for (int h = 0; h < (height); h++)
    {
        for (int w = 0; w < (width); w++)
        {
            //new array
            RGBTRIPLE pixel = image[h][w];
            // calculate average pixel value
            r = pixel.rgbtRed;
            b = pixel.rgbtBlue;
            g = pixel.rgbtGreen;
            average_pixel_value = round((r + b + g) / 3.0);

            //set each colour value to average value
            image[h][w].rgbtRed = image[h][w].rgbtBlue = image[h][w].rgbtGreen = average_pixel_value;
        }
    }
    return;
}
// creating function to limit pixel value to 255
int cap(int value)
{
    return value > 255 ? 255 : value;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0;w < width; w++)
        {
            //new array
            RGBTRIPLE pixel = image[h][w];
            //calculate new colour value using sepia formula
            int r = pixel.rgbtRed;
            int b = pixel.rgbtBlue;
            int g = pixel.rgbtGreen;
            image[h][w].rgbtRed = cap(round(0.393 * r + 0.769 * g + 0.189 * b ));
            image[h][w].rgbtGreen = cap(round(0.349 * r + 0.686 * g + 0.168 * b ));
            image[h][w].rgbtBlue = cap(round(0.272 * r + 0.534 * g + 0.131 * b ));
        }
    }
    return;
}

//creating function swap with pointers
void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width/2; w++)
        {
            swap(&image[h][w], &image[h][width-1-w]);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //creating temporary storage of image
    RGBTRIPLE temporary_image[height][width];
    //copying image to keep unaltered version to loop
    memcpy(temporary_image, image, sizeof(RGBTRIPLE) * height * width);

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            //variable to calculate average using no. of pixels accounted for
            float number_of_pixels = 0.0;
            //set RGB values to 0
            int r = 0;
            int g = 0;
            int b = 0;

            //create another nested for loop to locate pixels surrounding particular pixel *
            //  1 2 3
            //  4 * 6
            //  7 8 9
            //loop iterating rows over current row
            for (int i = -1; i <= 1; i++)
            {
                //loop iterating columns over current column
                for (int j = -1; j <= 1; j++)
                {
                    //if condition to check whether selected pixel is within bound
                    if ((i + h) != height && (i + h) != -1 && (j + w) != width && (j + w) != -1)
                    {
                        r += temporary_image[i + h][j + w].rgbtRed;
                        g += temporary_image[i + h][j + w].rgbtGreen;
                        b += temporary_image[i + h][j + w].rgbtBlue;
                        number_of_pixels++;
                    }
                }
            }

            //set new values of pixels to their blurred version
            image[h][w].rgbtRed = round(r / number_of_pixels);
            image[h][w].rgbtGreen = round(g / number_of_pixels);
            image[h][w].rgbtBlue = round(b / number_of_pixels);
        }
    }
}
