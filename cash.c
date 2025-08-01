#include <cs50.h>
#include <math.h>
#include <stdio.h>
int main(void)
{
    int cents; // Declaring a variable cents
    // Prompt the user for change owed.
    do
    {
        cents = get_int("Change owed (in cents): ");
    }
    while (cents < 0);
    // Initialisation of total coins counter
    int coins = 0;
    // Calculate number of Quarter (25 cents) and subtract their value
    coins += cents / 25;
    cents %= 25;
    // Calculate number of Dime (10 cents) and subtract their value
    coins += cents / 10;
    cents %= 10;
    // Calculate number of nickel (5 cents) and subtract their value
    coins += cents / 5;
    cents %= 5;
    // Calculate number of pennies (1 cents) and subtract their value
    coins += cents / 1;
    cents %= 1;

    // Print total number of coins used
    printf("%i\n", coins);
}
