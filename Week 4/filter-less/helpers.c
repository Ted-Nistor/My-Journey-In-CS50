#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Same logic with looping through each pixel at height-width coordinates, and assignin them pointers for each value.
            BYTE *red = &image[i][j].rgbtRed;
            BYTE *blue = &image[i][j].rgbtBlue;
            BYTE *green = &image[i][j].rgbtGreen;
            // the sepia value is correspondent to each formula.
            int sepiaBlue = round(.272 * (*red) + .534 * (*green) + .131 * (*blue));
            int sepiaGreen = round(.349 * (*red) + .686 * (*green) + .168 * (*blue));
            int sepiaRed = round(.393 * (*red) + .769 * (*green) + .189 * (*blue));
            // We must use a cap of 255 so that we don't have more than 255 in any of the rgb values.
            *blue = (sepiaBlue > 255) ? 255 : sepiaBlue;
            *green = (sepiaGreen > 255) ? 255 : sepiaGreen;
            *red = (sepiaRed > 255) ? 255 : sepiaRed;

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
