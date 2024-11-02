/*
 * File: credit.c
 * Description: check if the credit card is invalid or valid 
 *              (if valid display the name of credit card)
 * 
 * Algorithm: Luhn’s Algorithm
 */
#include <cs50.h>
#include <stdio.h>

long get_card(char *prompt);
char *check(long card);
int isvalid(long card);
int get_length(long card);
bool validating_checksum(long card);
int get_starting_num(long card);

/*
 * Function: main
 * --------------
 * take user's credit card number and display invalid or name of credit card if valid
 * 
 * return: 0
 */
int main(void)
{
    long card = get_card("Number: ");
    printf("%s", check(card));
}

/*
 * Function: get_card
 * ------------------
 * get credit card number from user that is non zero and non negative
 * 
 * prompt: char*. msg to be display to user to ask for number
 * 
 * return: long. credit card number which need to be check for valid or invalid
 */
long get_card(char *prompt)
{
    long n = 0;
    do
    {
        n = get_long("%s", prompt);
    } 
    while (n < 0);

    return n;
}

/*
 * Function: check
 * ---------------
 * check if credit card number is invalid or valid and gives name.
 * 
 * card: long. credit card number
 * 
 * return: char*. invalid (if card is invalid) and name of card if valid
 */
char *check(long card)
{
    int valid_card = isvalid(card);
    if (valid_card == 1)
    {
        return "AMEX\n";
    }
    else if (valid_card == 2)
    {
        return "MASTERCARD\n";
    }
    else if (valid_card == 3)
    {
        return "VISA\n";
    }
    else
    {
        return "INVALID\n";
    }  
}

/*
 * Function: isvald
 * ----------------
 * check if card is valid or not.
 * 
 * card: long. credit card number to be check
 * 
 * return: int. 1 for amex, 2 for mastercard, 3 for visa. 0 for invalid card
 */
int isvalid(long card)
{
    /*
        American Express
            length = 15
            starting num = 34 or 37
        MasterCard
            length = 16
            starting num = 51, 52, 53, 54, or 55
        Visa
            length = 13 or 16
            starting num = 4 (39 > < 50)

        Luhn’s Algorithm == true. 
    */
    int length = get_length(card);
    int start_with = get_starting_num(card);
    bool checksum = validating_checksum(card);

    if (length == 15 && (start_with == 34 || start_with == 37) && checksum)
    {
        return 1;
    }
    else if (length == 16 && (start_with > 50 && start_with < 56) && checksum)
    {
        return 2;
    }
    else if ((length == 13 || length == 16) && (start_with > 39 && start_with < 50) && checksum)
    {
        return 3;
    }        
    return 0;
}

/*
 * Function: get_length
 * --------------------
 * get the length of a long number 
 * 
 * card: long. long number whose length is to be calculated
 * 
 * return: int. length of the number
 */
int get_length(long card)
{

    int length = 0;
    // truncrating the card till it hits 0 
    // also updating the length till cards hit zero
    while (card > 0)
    {
        card /= 10;
        length++;
    }
    return length;
}

/*
 * Function: get_starting_num
 * --------------------------
 * get the starting 2 number from a long number
 * 
 * card: long. whose starting number to be extracted
 * 
 * return: int. extracted starting 2 number
 */
int get_starting_num(long card)
{
    // we can get the starting number by dividing the card 
    // and truncrating it till it hits less then 100 which 
    // will get us 99 and bellow
    while (card > 100)
    {
        card /= 10;
    }
    return (int) card;
}

/*
 * Function: validating_checksum
 * -----------------------------
 * using the Luhn’s Algorithm to check if the card number is valid or not
 * 
 * Algorithm: Luhn’s Algorithm
 * 
 * card: long. credit card number
 * 
 * return: bool. true if Luhn’s Algorithm is valid else false
 */
bool validating_checksum(long card)
{
    int sum = 0;
    int last_num = 0; 
    for (int i = 0; card > 0; i++, card /= 10)
    {
        // getting the last number from the card number
        last_num = card % 10;

        // checking the position of the number we took out
        // Multiply every other digit by 2, 
        // starting with the number’s second-to-last digit, 
        // and then add those products’ digits together.
        if (i % 2 == 1)
        {
            // if the position is odd then multiply by 2
            last_num *= 2;
            if (last_num > 9)
            {
                // if after multiplying by 2 
                // if last number is > 9 then the 2 number 
                // should be seperated and added togather
                last_num = (last_num / 10) + (last_num % 10);
            }
            sum += last_num;
        }
        else
        {
            // if position is even just add
            sum += last_num;
        }
    }

    // extracting the last number
    sum = sum % 10;
    // to be valid the last number should be always zero
    if (sum == 0)
    {
        return true;
    }
    return false;
}