/**
 * \file scrabble.c
 * \brief 
 * game that gives point to the given word and display the winner.
 */
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \typedef players
 * 
 * \brief
 * Represent a player with their words, player number and score.
 * 
 * this structure holds the word that player gives 
 * with the player number or representation of player.
 * and the total score of player
 */
typedef struct players 
{
    char *word; /** words string that player gives */
    int player; /** player number or representation */
    int score;  /** total score of the player */
} players;

players *generate_players(int no_of_players);
void calculate_score(players *player, const int point[], int no_of_players);
void display_winner(players *player, int no_of_players);

/**
 * \brief
 * it generate the player to be able to play
 * calculate the score of players 
 * and display the winner
 * This function assigns the specified width and height to a Rectangle struct.
 *
 * \return 0 on sucess | 1 if player is not generated
 */
int main(void)
{
    const int no_of_players = 2;
    const int point[] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10,
    };

    players *player = generate_players(no_of_players);

    if (!player)
    {
        return 1;
    }

    calculate_score(player, point, no_of_players);

    display_winner(player, no_of_players);

    free(player);
    return 0;
}

/**
 * \brief
 * display the winner or tie if the score is same.
 * 
 * \param player player data their word, representation and score
 * \param no_of_players numbers of players
 * 
 * \return void
 */
void display_winner(players *player, int no_of_players)
{
    int max_score = 0;
    int winner = 0;
    bool tie = false;

    for (int i = 0; i < no_of_players; i++)
    {
        // if the score is same as max score than its a tie
        if (player[i].score == max_score && max_score > 0)
        {
            tie = true;
        }
        // updating the max score by just updating with highest score
        // also keeping the player number
        else if (player[i].score > max_score)
        {
            max_score = player[i].score;
            winner = player[i].player;
            tie = false;
        }
    }
    if (tie)
    {
        printf("Tie!\n");
    }
    // displaying the winner player 
    else
    {
        printf("Player %i wins!\n", winner);
    }
}

/**
 * \brief calculate the total score of players and update their score
 * 
 * \param player players data with words score and theeir representation
 * \param point pre defined points of the character length 26
 * \param no_of_players the numbers of players 
 * 
 * \return void
 */
void calculate_score(players *player, const int point[], int no_of_players)
{
    // calculating score for all the players
    for (int i = 0; i < no_of_players; i++)
    {
        // checking the points for the words given by players
        int length = strlen(player[i].word);
        for (int j = 0; j < length; j++)
        {
            // checking if the letter is a alphabet
            if (isalpha(player[i].word[j]))
            {
                // changing the letter to upper case 
                // as given point length is 26 and the points is in order
                // of A to Z
                // position is just the player word letter - A(int 65 ascii)
                int position_of_point = toupper(player[i].word[j]) - 'A';
                player[i].score += point[position_of_point];
            }
        }
    }
}

/**
 * \brief generate numbers of player and initialize the word score and player number
 * 
 * \param no_of_players number of players
 * 
 * \return the generated players player number, word and default score 0
 */
players *generate_players(int no_of_players)
{
    players *player = malloc(no_of_players * sizeof(players));
    if (!player)
    {
        return NULL;
    }

    for (int i = 0; i < no_of_players; i++)
    {
        player[i].player = i + 1;
        player[i].word = get_string("Player %i: ", player[i].player);
        player[i].score = 0;
    }

    return player;
}
