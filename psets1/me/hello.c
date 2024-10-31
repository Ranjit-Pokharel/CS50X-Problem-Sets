/*
 * File: hello.c
 * Description: Greet user with hello, <name>
 */

#include <cs50.h>
#include <stdio.h>

/*
 * Function: main
 * --------------
 * greet user name with hello, <name>.
 *  
 * return: 0
 */
int main(void)
{
    char *name = get_string("What's your name? ");

    printf("hello, %s\n", name);

    return 0;
}