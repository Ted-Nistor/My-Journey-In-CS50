#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0 ; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            printf("%i\n", ranks[rank]);
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{

    for (int i = 0 ; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
            // printf("%i ", preferences[ranks[i]][ranks[j]]);

        }
        //printf("\n");
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i ", preferences[i][j]);
        }
        printf("\n");
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0 ; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
                //printf("winner : %i\n", pairs[i].winner);
                //printf("loser : %i\n", pairs[i].loser);
                //printf("%i", i );
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
                //printf("winner : %i\n", pairs[i].winner);
                //printf("loser : %i\n", pairs[i].loser);
                //printf("%i", i );

            }

        }

    }
    for (int i = 0; i < pair_count; i++)
    {
        printf("w: %i ", pairs[i].winner);
        printf("l: %i ", pairs[i].loser);
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int win_amount[pair_count];
    for (int i = 0; i < pair_count; i++)
    {

        //printf("w: %i ", pairs[i].winner);
        //printf("l: %i ", pairs[i].loser);
        win_amount[i] = preferences[pairs[i].winner][pairs[i].loser];
    }
    printf("\n");
    int temp;
    pair temp2;
    int counter = -1;
    while (counter != 0)
    {
        counter = 0;
        for (int i = 0 ; i < pair_count - 1 ; i++)
        {
            if (win_amount[i] < win_amount[i + 1])
            {
                counter++;
                temp = win_amount[i];
                temp2 = pairs[i];
                win_amount[i] = win_amount[i + 1];
                win_amount[i + 1] = temp;
                pairs[i] = pairs[i + 1];
                pairs[i + 1] = temp2;
            }
        }
    }
    for (int i = 0 ; i < pair_count; i++)
    {
        //printf("%i ", pairs[i].winner);
        printf("%i ", win_amount[i]);
    }
    printf("\n");

    return;
}

bool has_cycle(int winner, int loser)
{
    while (winner != -1 && winner != loser)
    {
        bool found = false;
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[i][winner])
            {
                found = true;
                winner = i;
            }
        }
        if (!found)
        {
            winner = -1;
        }
    }
    if (winner == loser)
    {
        return true;
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!has_cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

// Print the winner of the election
void print_winner(void)
{
    bool found_source = true;
    for (int i = 0; i < candidate_count; i++)
    {
        found_source = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                found_source = false;
                break;
            }
        }
        if (found_source)
        {
            printf("%s\n", candidates[i]);
        }
    }

    // TODO
    return;
}