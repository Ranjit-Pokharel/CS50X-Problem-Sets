/**
 * \file runoff
 * \brief
 * ranked-choice voting system. 
 * \paragraph 
 * a ranked-choice system, voters can vote for more than one candidate. 
 * Instead of just voting for their top choice, they can rank the candidates in order of preference
 */

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
/**
 * \typedef candidate
 * \brief
 * a structure of candidate that holds 
 * candidate name with their vote and 
 * if they are eliminated or not
 */
typedef struct
{
    string name;     /** name of candidate */
    int votes;       /** total vote of candidate */
    bool eliminated; /** if eliminated or not */
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

/**
 * \brief
 * check for cli argument to be grater then 2 (min 1 candidates should be provided)
 * check if candidates count doesn't maxout than fixed 9
 * insilized the candidates name and initial vote count as 0
 * ask for voters count and ask that number of voters for the name to be voted
 * also check for the number of voter max voter is 100
 * at last print the winner
 * 
 * \param argc number of command line argument
 * \param argv[] array of string from cli arguments
 * 
 * \return
 * 1 if no cli argument provided || 2 if candidate provided is grater then 9 ||
 * 3 if voter number is grater than max voter || 4 if the name provided by voter is invalid ||
 * 0 default on success
 */
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
/**
 * \brief
 * update the voter's preferences of candidates with rank
 * 
 * \param voter voter indication
 * \param rank candidate indication
 * \param name name of the candidate
 * 
 * \return
 * true if preference is updated || false if unable to update
 */
bool vote(int voter, int rank, string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
/**
 * \brief
 * update the candidates votes based on the rank of the voters
 * 
 * \param void
 * 
 * \return void
 */
void tabulate(void)
{
    // TODO
    int prefere_candidate;
    for (int i = 0; i < voter_count; i++)
    {
        // here i represent the voter
        for (int j = 0; j < candidate_count; j++)
        {
            // prefrences[i][j] provide the rank of the candidate
            prefere_candidate = preferences[i][j];
            // here j represent candidate
            if (!candidates[prefere_candidate].eliminated)
            {
                // if only the candidate is not eliminated
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
/**
 * \brief 
 * display the winner of the election
 * 
 * \param void
 * 
 * \return
 * true if the candidate who won is displayed || false if not
 */
bool print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        int majority_vote = round(voter_count / 2);

        if (candidates[i].votes > majority_vote)
        { 
            printf("winner %s\n", candidates[i].name);
            return true;
        }
    }

    return false;  
}

// Return the minimum number of votes any remaining candidate has
/**
 * \brief 
 * find the minimum vote in election 
 * 
 * \param void
 * 
 * \return minimum votes possible among the candidates
 */
int find_min(void)
{
    // TODO
    int min = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < min && !candidates[i].eliminated)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
/**
 * \brief
 * finds if the candidates are tie or not
 * 
 * \param min minimum value of vote
 * 
 * \return true if it's a tie || false if not
 */
bool is_tie(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes != min)
            {
                return false;
            }
        }
    }
    
    return true;
}

// Eliminate the candidate (or candidates) in last place
/**
 * \brief 
 * eliminate the candidates 
 * 
 * \param min minimum vote possible 
 * \return void
 */
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && !candidates[i].eliminated)
        {
            candidates[i].eliminated = true;
        }
    }  
    return;
}
