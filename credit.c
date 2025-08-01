#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // Prompt the user for credit card number
    long number = get_long("Number: ");
    // Apply Luhn's Algorithm to check validity
    int sum = 0;
    long temp = number;
    int position = 0;
    // Traverse each digit from right to left
    while (temp > 0)
    {
        int digit = temp % 10;
        // for even position, add digit directly
        if (position % 2 == 0)
        {
            sum += digit;
        }
        else // For odd position, double the digit
        {
            int doubled = digit * 2;
            // If result is two digits, add the digits separately
            sum += (doubled / 10) + (doubled % 10);
        }
        temp /= 10; // Remove the last digit
        position++; // Move to next position
    }
    if (sum % 10 != 0) // If checksum is not divisible by 10, its invalid
    {
        printf("INVALID\n");
        return 0;
    }
    long start = number; // Find starting digit and length of the card number
    int length = 0;
    // Reduce to the first two digits and count total length
    while (start >= 100)
    {
        start /= 10;
        length++;
    }
    length += 2; // Add 2 because we stopped at 2 digits

    // Determining card type using starting digits and length of card number
    if ((start == 34 || start == 37) && length == 15)
    {
        printf("AMEX\n"); // American Express
    }
    else if ((start >= 51 && start <= 55) && length == 16)
    {
        printf("MASTERCARD\n"); // MasterCard
    }
    else if ((start / 10 == 4) && (length == 13 || length == 16))
    {
        printf("VISA\n"); // VISA Card
    }
    else
    {
        printf("INVALID\n"); // Anything else is invalid
    }
}
