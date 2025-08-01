#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int height; // declaring a variable named height
    // prompt for height from 1 to 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    for (int i = 0; i < height; i++) // here 'i' is row
    {
        for (int j = 0; j < height - i - 1; j++) // here 'j' is space
        {
            printf(" ");
        }
        // printing left hashes
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        // printing gaps (2 spaces)
        printf("  ");
        // printing right hashes
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
