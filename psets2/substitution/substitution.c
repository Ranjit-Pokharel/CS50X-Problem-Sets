/**
 * \file substitution.c
 * \brief
 * encrypt a message by replacing every letter with another letter.
 * provided key: in this case, a mapping of each of the letters of the alphabet 
 * to the letter it should correspond to when we encrypt it. 
 * To “decrypt” the message, the receiver of the message would need to know the key, 
 * so that they can reverse the process: translating the encrypt text back into 
 * the original message
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_valid_key(char *key);
char *cipher(char *plaintext, const char *key);

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
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // if given key is not valid
    if (!is_valid_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;        
    }

    const char *KEY = argv[1];

    char *text = get_string("plaintext: ");

    char *ciphertext = cipher(text, KEY);
    if (!ciphertext)
    {
        printf("memory isssue\n");
        return 1;
    }

    printf("ciphertext: %s\n", ciphertext);

    free(ciphertext);
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
char *cipher(char *plaintext, const char *key)
{
    int length = strlen(plaintext);

    char *ciphertext = malloc(sizeof(char) * length + 1);
    if (!ciphertext)
    {
        return NULL;
    }
    ciphertext[-1] = '\0';

    int position = 0;
    int starting_alphabet = 'A';

    for (int i = 0; i < length; i++)
    {
        // check if the given char of the plainte
        if (isalpha(plaintext[i]))
        {
            position = toupper(plaintext[i]) - starting_alphabet;

            if (isupper(plaintext[i]))
            {
                ciphertext[i] = toupper(key[position]);
            }
            else
            {
                ciphertext[i] = tolower(key[position]);
            }   
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    return ciphertext;
}

/**
 * \brief 
 * check if the given key is of length 26 or
 * no duplication or if its only alphabet 
 * (not numeric)
 * 
 * \param strings the key to be checked if its valid or not.
 * 
 * \return
 * True if its valid || False if not
 */
bool is_valid_key(char *key)
{
    int length = strlen(key);
    // if length is not 26 (A to Z) not valid
    if (length != 26)
    {
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        // if the given char is not alphabet not valid
        if (!isalpha(key[i]))
        {
            return false;
        }

        // checking for duplicate
        // check the char I for every char j in that string till it hits length
        for (int j = i + 1; j < length; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
    return true;
}