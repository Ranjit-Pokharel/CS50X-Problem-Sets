/**
 * \file readability
 * \brief
 * a program that calculates the approximate grade level needed to comprehend some text.
 * 
 * Coleman-Liau index
 * ------------------
 * index = 0.0588 * L - 0.296 * S - 15.8
 */

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/**
 * \typedef TextStatistics
 * \brief Stores basic statistics of a text.
 *
 * This structure holds counts of letters, words, and sentences in a given text.
 */
typedef struct TextStatistics
{
    float no_of_letter;   /** Number of letters in the text */
    float no_of_words;    /** Number of words in the text */
    float no_of_sentence; /** Number of sentences in the text */
} TextStatistics;

int coleman_liau_index(char *text);

/**
 * \brief
 * get the user input text which grade is to be check
 * if coleman liau index is less then 1 its before grade 1
 * if grater than 15 its 16+ grade 
 * 
 * \param void
 * 
 * \return 0 on sucess
 */
int main(void)
{
    int length = 0;
    char *text = NULL;
    do
    {
        text = get_string("Text: ");
        length = strlen(text);
    } 
    while (length < 1);
    
    int grade = coleman_liau_index(text);

    if (grade > 15)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

    return 0;
}

/**
 * \brief
 * A number of “readability tests” have been developed over the years that define formulas 
 * for computing the reading level of a text. One such readability test is the Coleman-Liau index. 
 * The Coleman-Liau index of a text is designed to output that (U.S.) grade level 
 * that is needed to understand some text. The formula is
 * index = 0.0588 * L - 0.296 * S - 15.8
 * 
 * \param text text to be calculated.
 * 
 * \return
 * rounded index
 */
int coleman_liau_index(char *text)
{
    TextStatistics stat;
    stat.no_of_letter = 0;
    stat.no_of_sentence = 0;
    // space determine a word but at end of text there is no space 
    // so word is always 1 to indicate last word of text.
    stat.no_of_words = 1;

    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        // check for sentences
        bool is_period = text[i] == '.';
        bool is_exclamation = text[i] == '!';
        bool is_question_mark = text[i] == '?';
        bool is_sentence = is_exclamation || is_period || is_question_mark;

        if (is_sentence)
        {
            stat.no_of_sentence++;
        }

        // check for words as word end with space
        else if (text[i] == ' ')
        {
            stat.no_of_words++;
        }
        
        // only alphabets
        else if (isalpha(text[i]))
        {
            stat.no_of_letter++;
        }
    }

    // index = 0.0588 * L - 0.296 * S - 15.8
    // L is average letter per 100 words
    float L = (stat.no_of_letter / stat.no_of_words) * 100;
    // S is averade sentence per 100 words
    float S = (stat.no_of_sentence / stat.no_of_words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    return round(index);
}
