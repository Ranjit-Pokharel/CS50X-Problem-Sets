/**
 * \file hello.c
 * \brief
 * Greet user with hello, <name>
 */

#include <cs50.h>
#include <stdio.h>

/**
 * \brief
 * greet user name with hello, <name>.
 *  
 * \param void
 * 
 * \return 0
 */
int main(void)
{
    char *name = get_string("What's your name? ");

    printf("hello, %s\n", name);

    return 0;
}