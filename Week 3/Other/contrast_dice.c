#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    int ability_dice, challenge_dice, num_ability_dice, num_challenge_dice;
    int success_count = 0, failure_count = 0, neutral_count = 0, edge_count = 0, threat_count = 0;
    bool re_roll = false;

    /* Ask user to enter number of Ability Dice and Challenge Dice to roll */
    printf("Enter number of Ability Dice to roll (between 2 and 5): ");
    scanf("%d", &num_ability_dice);
    printf("Enter number of Challenge Dice to roll (between 0 and 10): ");
    scanf("%d", &num_challenge_dice);

    /* Ensure user entered valid number of Ability Dice and Challenge Dice to roll */
    if (num_ability_dice < 2 || num_ability_dice > 5 || num_challenge_dice < 0 || num_challenge_dice > 10)
    {
        printf("Invalid number of Ability Dice or Challenge Dice entered.\n");
        return 0;
    }

    /* Initialize random seed */
    srand(time(0));

    /* Generate random numbers for Ability Dice */
    for (int i = 0; i < num_ability_dice; i++) {
        ability_dice = rand() % 6 + 1;
        /* Print the results of each individual roll */
        printf("Results of Ability Dice Roll: %d\n", ability_dice);

        if (ability_dice >= 5) {
            success_count++;
        } else if (ability_dice >= 2 && ability_dice <= 4) {
            neutral_count++;
        } else if (ability_dice == 1) {
            edge_count++;
        }
    }

    /* Generate random numbers for Challenge Dice */
    for (int i = 0; i < num_challenge_dice; i++) {
        challenge_dice = rand() % 6 + 1;

        /* Print the results of each individual roll */
        printf("Results of Challenge Dice Roll: %d\n", challenge_dice);

        if (challenge_dice == 6) {
            failure_count++;
        } else if (challenge_dice == 1) {
            threat_count++;
        }
    }

    /* Calculate the total number of Success, Failure, Neutral, Edge and Threat after Cancellation */
    int total_success = success_count - failure_count;
    int total_edge = edge_count - threat_count;

    /* Print the total number of Success, Failure, Neutral, Edge and Threat after Cancellation */
    printf("Total number of Success after Cancellation: %d\n", total_success);
    printf("Total number of Failure after Cancellation: %d\n", failure_count);
    printf("Total number of Neutral after Cancellation: %d\n", neutral_count);
    printf("Total number of Edge after Cancellation: %d\n", total_edge);
    printf("Total number of Threat after Cancellation: %d\n", threat_count);

    /* If user has no success, ask if he wants to re-roll all Neutral */
    if (total_success <= 0 && neutral_count > 0) {
        char response;
        printf("Do you want to re-roll all Neutral? (y/n): ");
        scanf(" %c", &response);

        if (response == 'y') {
            re_roll = true;
        }
    }

    /* Re-roll all Neutral dice if user accepted */
    if (re_roll) {
        neutral_count = 0;
        for (int i = 0; i < num_ability_dice; i++) {
            ability_dice = rand() % 6 + 1;
            /* Print the results of each individual roll */
            printf("Results of Ability Dice Roll: %d\n", ability_dice);

            if (ability_dice >= 5) {
                success_count++;
            } else if (ability_dice >= 2 && ability_dice <= 4)
{
                neutral_count++;
            } else if (ability_dice == 1) {
                edge_count++;
            }
        }

        /* Calculate the total number of Success, Failure, Neutral, Edge and Threat after Cancellation */
        total_success = success_count - failure_count;
        total_edge = edge_count - threat_count;

        /* Print the total number of Success, Failure, Neutral, Edge and Threat after Cancellation */
        printf("Total number of Success after Cancellation: %d\n", total_success);
        printf("Total number of Failure after Cancellation: %d\n", failure_count);
        printf("Total number of Neutral after Cancellation: %d\n", neutral_count);
        printf("Total number of Edge after Cancellation: %d\n", total_edge);
        printf("Total number of Threat after Cancellation: %d\n", threat_count);
    }

    return 0;
}