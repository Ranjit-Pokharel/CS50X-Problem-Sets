/**
 * \file caeser.c
 * \brief
 * encrypt the given text with key which is provide as cli argument
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_digit(char *strings);
char *cipher(char *palintext, const int key);

/**
 * \brief
 * takes key from command line argument and
 * ask user for text to be encrypted
 * display the encrypted text.
 * 
 * \param argc length of the argument passed including the program name
 * \param argv array of string 
 * 
 * \return 
 * 0 on success
 * 1 on if key is not provided or the provided key is decimal || negative || not a number.
 */
int main(int argc, char *argv[])
{
    // if user doesn't give proper cli argument 
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // if the given key by user is not numeric
    if (!is_digit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;        
    }

    // converting string to int
    const int KEY = atoi(argv[1]);

    char *text = get_string("plaintext: ");

    char *ciphertext = cipher(text, KEY);
    if (!ciphertext)
    {
        printf("memory isssue\n");
        return 1;
    }

    printf("ciphertext: %s\n", ciphertext);
}

/**
 * \brief
 * encrypt the given string text with a secret key
 * 
 * \param plaintext string of text to be cipher
 * \param key secret key to be used
 * 
 * \return char *ciphertext string of encrypted text || NULL if memory allocation fail.
 */
char *cipher(char *plaintext, const int key)
{
    int length = strlen(plaintext);
    int wraptext = 0;
    // there are 26 char in english alphabet
    int alphabet_range = 26;
    // the starting of english alphabet is A;
    int starting_alphabet = 'A';

    char *ciphertext = malloc(sizeof(char) * length + 1);
    if (!ciphertext)
    {
        return NULL;
    }
    ciphertext[-1] = '\0';

    for (int i = 0; i < length; i++)
    {
        // if the char of string is alpha then only modify and add to ciphertext
        if (isalpha(plaintext[i]))
        {
            // wrap formula wrap = S + ((O + K - S) % range)
            // where:
            // S = starting char or number of the range (A to Z)
            // O = the char of the given string of text
            // K = secerate key
            // range = total length of the range (A - Z) that is 26
            wraptext = starting_alphabet + 
                       ((toupper(plaintext[i]) + key - starting_alphabet) % alphabet_range);

            if (isupper(plaintext[i]))
            {
                // if the char of string is upper chyper as upper
                ciphertext[i] = toupper((char) wraptext);
            }
            else
            {
                // if char of string is lower chyper as lower
                ciphertext[i] = tolower((char) wraptext);
            }
        }
        // if char of string is not alphabet just add as it is
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    return ciphertext;
}

/**
 * \brief 
 * check if the given string is a digit or not
 * (alpha-numeric)
 * 
 * \param strings the string which might be numeric.
 * 
 * \return
 * True if its a digit || False if not a digit
 */
bool is_digit(char *strings)
{
    int length = strlen(strings);

    for (int i = 0; i < length; i++)
    {
        // if tha given numeric string is not a number
        if (!isdigit(strings[i]))
        {
            return false;
        }
    }
    return true;
}