/**
 * \file: cash.c
 * \brief
 * Gives the total numbers of coins to give for a given change. 
 */
#include <cs50.h>
#include <stdio.h>

/**
 * \typedef coins
 * \brief
 * Represents a coin with amount and total_coins fields.
 * This structure holds information about a coin's amount and the total
 * number of coins. It is intended to be used wherever a simple 
 * integer-based representation of a coin's value and total quantity is needed.
 */
typedef struct
{
    int amount;      /**amount of the coin */
    int total_coins; /**total number of coins */
} coins;

int coin_dispensing(int change_own);
int get_change(char *prompt);

/**
 * \brief
 * get the change from user and display the total 
 * coin to be given
 * 
 * \param void
 * 
 * \return 0
 */
int main(void)
{
    int change_own = get_change("Change owned: ");
    int coin = coin_dispensing(change_own);
    printf("%i\n", coin);
    return 0;
}

/**
 * \brief
 * get a valid change non negative amount from user.
 * 
 * \param prompt (char*): text to be dispay to ask for change.
 * 
 * \return n (int): the valid amount
 */
int get_change(char *prompt)
{
    // get non negative number
    int n = 0;
    do
    {
        n = get_int("%s", prompt);
    } 
    while (n < 0);
    return n;
}

/**
 * \brief
 * calculate total coins to be given to customers.
 * Algorithms: Greedy algorithm.
 * 
 * \param change_own (int): change that is to be return to the customer
 * 
 * \return total (int): total coins to be given to customers
 */
int coin_dispensing(int change_own)
{
    // coins initilizations
    // amount and total coins to be given (0 default)
    coins quaters;
    quaters.amount = 25;
    quaters.total_coins = 0;

    coins dimes;
    dimes.amount = 10;
    dimes.total_coins = 0;

    coins nickles;
    nickles.amount = 5;
    nickles.total_coins = 0;

    coins pennies;
    pennies.amount = 1;
    pennies.total_coins = 0;

    // change own is substractes and each substraction indicate 1 coins
    while (change_own != 0)
    {
        // using greedy algorithm to 
        // substract large part 1st
        // each substraction of the coins will add total coin by 1
        if (change_own >= quaters.amount)
        {
            change_own -= quaters.amount;
            quaters.total_coins++;
        }
        else if (change_own >= dimes.amount)
        {
            change_own -= dimes.amount;
            dimes.total_coins++;
        }
        else if (change_own >= nickles.amount)
        {
            change_own -= nickles.amount;
            nickles.total_coins++;
        }
        else if (change_own >= pennies.amount)
        {
            change_own -= pennies.amount;
            pennies.total_coins++;
        }
    }

    // final total coins to be return
    // adding all the total coins 
    int total = quaters.total_coins + dimes.total_coins + nickles.total_coins + pennies.total_coins;

    return total;
}