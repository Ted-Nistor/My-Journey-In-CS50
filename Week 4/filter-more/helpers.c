#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel at the height and widht coordinates.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // to work easier with the values and not to repeat image[i][j].rgbt , use a pointer for each RGB pixel.
            BYTE *red = &image[i][j].rgbtRed;
            BYTE *blue = &image[i][j].rgbtBlue;
            BYTE *green = &image[i][j].rgbtGreen;
            // 255 is white, 0 is black, so we ignore these values, because they are already from the grey specter.
            if ((*red != 255 || *red != 0) && (*blue != 255 || *blue != 0) && (*green != 255 || *green != 0))
            {
                // Each pixel should be of the same average value, so we first calculate the average, then assign that same value to each pixel.
                float average = (*red + *blue + *green) / 3.0;
                *red = round(average);
                *blue = round(average);
                *green = round(average);
            }


        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int end = (width - 1) / 2;
        for (int j = 0; j <= end; j++)
        {
            // loop through the height, but we also need an end value which determine the half position of the picture. so the half is width - 1 / 2.
            //we just replace the pixel with the value of the pixel from the end of the half of the picture.
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // we need nested loops for this because we first loop through the coordinates and then we need a matrix for each coordinate. the matrix is a 3 x 3 square of pixels.
    // we can make another loop running from -1 to + 1 (because the matrix will be something like : [i-1][j-1]; [i][j - 1]; [i + 1][j - 1] and so on for every permutation).
    // we also need to make sure that we don't get out of the array , so i-1 respectively j - 1 should be > than 0; also while looping, we should stay within the limits of height and width.
    int sumR, sumG, sumB, counter;
    // adding a temporary storage value ensures that we don't change the actual value of the pixels during the loop process. so we store everything in a temporary value and only after that
    // we assing the temporary value to each pixel.
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sumR = 0;
            sumG = 0;
            sumB = 0;
            counter = 0;
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (i + x >= 0 && i + x < height && j + y >= 0 && j + y < width)
                    {
                        sumR += image[i + x][j + y].rgbtRed;
                        sumG += image[i + x][j + y].rgbtGreen;
                        sumB += image[i + x][j + y].rgbtBlue;
                        counter++;
                    }
                }
            }
            temp[i][j].rgbtRed = round((double)sumR / counter);
            temp[i][j].rgbtGreen = round((double)sumG / counter);
            temp[i][j].rgbtBlue = round((double)sumB / counter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Gx_sum_red = 0;
            int Gy_sum_red = 0;
            int Gx_sum_green = 0;
            int Gy_sum_green = 0;
            int Gx_sum_blue = 0;
            int Gy_sum_blue = 0;

            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (i + x >= 0 && i + x < height && j + y >= 0 && j + y < width)
                    {
                        Gx_sum_red += image[i + x][j + y].rgbtRed * Gx[x + 1][y + 1];
                        Gy_sum_red += image[i + x][j + y].rgbtRed * Gy[x + 1][y + 1];
                        Gx_sum_green += image[i + x][j + y].rgbtGreen * Gx[x + 1][y + 1];
                        Gy_sum_green += image[i + x][j + y].rgbtGreen * Gy[x + 1][y + 1];
                        Gx_sum_blue += image[i + x][j + y].rgbtBlue * Gx[x + 1][y + 1];
                        Gy_sum_blue += image[i + x][j + y].rgbtBlue * Gy[x + 1][y + 1];
                    }
                }
            }

            int sum_red = round(sqrt(pow(Gx_sum_red, 2) + pow(Gy_sum_red, 2)));
            int sum_green = round(sqrt(pow(Gx_sum_green, 2) + pow(Gy_sum_green, 2)));
            int sum_blue = round(sqrt(pow(Gx_sum_blue, 2) + pow(Gy_sum_blue, 2)));
            temp[i][j].rgbtRed = sum_red > 255 ? 255 : sum_red;
            temp[i][j].rgbtGreen = sum_green > 255 ? 255 : sum_green;
            temp[i][j].rgbtBlue = sum_blue > 255 ? 255 : sum_blue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }

    return;
}