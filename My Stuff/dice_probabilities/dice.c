#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Calculates the number of successes obtained from rolling n dice
int roll_dice(int n) {
    int successes = 0;
    for (int i = 0; i < n; i++) {
        int roll = rand() % 6 + 1;
        if (roll == 5) {
            successes += 1;
        } else if (roll == 6) {
            successes += 2;
        }

    }
    return successes;
}

int main() {
    srand(time(NULL)); // Initialize random number generator
    printf("Number of dice,Successes,Probability\n");
    FILE *inptr = fopen ("probability.txt", "w");
    if (inptr == NULL)
    {
        return 1;
    }
    for (int x = 1; x <= 10; x++) {
        for (int s = 0; s <= 5; s++) {
            int num_trials = 1000000;
            int num_successes = 0;
            for (int i = 0; i < num_trials; i++) {
                if (roll_dice(x) >= s) {
                    num_successes++;
                }

            }
            double probability = (double) num_successes / num_trials;
            printf("Dice:%d, Successes: %d, Probability: %f %%\n", x, s, probability * 100);
            fprintf(inptr,"Dice:%d, Successes: %d, Probability: %f %%\n", x, s, probability * 100);

        }
    }
    fclose(inptr);
    return 0;
}
