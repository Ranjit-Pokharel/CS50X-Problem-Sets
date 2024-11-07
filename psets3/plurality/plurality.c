/**
 * \file pluraty.c
 * \brief
 * “plurality vote” (also known as “first-past-the-post” or “winner take all”). 
 * In the plurality vote, every voter gets to vote for one candidate. 
 * At the end of the election, whichever candidate has the greatest number of votes 
 * is declared the winner of the election.
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

/**
 * \typedef candidate
 * \brief
 * structure holding the name of candidates of election
 * and their total votes
 */
// Candidates have name and vote count
typedef struct
{
    string name; /** name of candidates */
    int votes;   /** total votes of the candidates */
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes

bool vote(string name);
void print_winner(void);

/**
 * \brief
 * check for cli argument to be grater then 2 (min 1 candidates should be provided)
 * check if candidates count doesn't maxout than fixed 9
 * insilized the candidates name and initial vote count as 0
 * ask for voters count and ask that number of voters for the name to be voted
 * at last print the winner
 * 
 * \param argc number of command line argument
 * \param argv[] array of string from cli arguments
 * 
 * \return
 * 1 if no cli argument provided || 2 if candidate provided is grater then 9 ||
 * 0 default on success
 */
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
/**
 * \brief
 * check if the given name of candidate is in the candidates list
 * if yes update their vote count
 * 
 * \param name name of candidate to be check
 * 
 * \return 
 * true if the candidate name in the list || false if not in the list
 */
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
/**
 * \brief
 * display the winner 
 * 
 * \param void
 * 
 * \return
 * void
 */
void print_winner(void)
{
    // TODO
    int highest_vote = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        // gets the highest vote 
        if (candidates[i].votes > highest_vote)
        {
            highest_vote = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        // check for the highest vote
        if (highest_vote == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}