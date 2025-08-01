#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int height; // Declaring a variable named height
    // Taking height input from user.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); // Taking inclusive height between 1 and 8
    // Loop through each row
    for (int i = 0; i < height; i++) // Here 'i' is row
    {
        for (int j = 0; j < height - i - 1; j++) // Here 'j' is space
        {
            printf(" ");
        }
        // Printing Hashtags(#)
        for (int h = 0; h <= i; h++) // Here 'h' is hash
        {
            printf("#");
        }
        printf("\n"); // Change to next line
    }
}
