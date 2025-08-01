#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// Function Prototype
int computer_score(string word);
// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int main(void)
{
    // Get words as input for both player 1 and player 2
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    // Calculate Scores
    int score1 = computer_score(word1);
    int score2 = computer_score(word2);
    // Compare scores and declare the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie\n");
    }
}
// Function to compute score of the word
int computer_score(string word)
{
    int score = 0;
    // Iterate thorugh each character of the word
    for (int i = 0; i < strlen(word); i++)
    {
        // Check if the character is a letter
        if isalpha (word[i])
        {
            // Convert to uppercase or lowercase to get index
            int index = toupper(word[i]) - 'A';
            score += POINTS[index];
        }
    }
    return score;
}
