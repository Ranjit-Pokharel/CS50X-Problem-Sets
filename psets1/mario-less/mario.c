/*
 * File: mario.c
 * Description: Print right-aligned pyramid of bricks. at the end of Super mario Bros world 1-1.
 */
#include <cs50.h>
#include <stdio.h>

int get_height(char *prompt);
void draw_pyramid(int height);
void row_print(int height, int row_level);

/*
 * Function: main
 * --------------
 * take user input height of pyramid draw the pyramid.
 * 
 * return: 0
 */
int main(void)
{
    int height = get_height("Height: ");
    draw_pyramid(height);
    return 0;
}

/*
 * Function: draw_pyramid
 * ----------------------
 * initilize starting row (first row) from where the pyramid is printed.
 * 
 * height: int. height of the pyramid to be print.
 */
void draw_pyramid(int height)
{
    int starting_row = 1;
    row_print(height, starting_row);
}

/*
 * Function: row_print
 * -------------------
 * print each row with a brick as #. recursive function.
 * 
 * height: int. height of the pyramid.
 * row_level: int. The row that is to be printed
 * 
 * returns: function is return if the height is less then the low_level as row cannot be greater 
 *          then the given height.
 */
void row_print(int height, int row_level)
{
    // height cannot be less then row to be print.
    if (height < row_level)
    {
        return;
    }

    // to make right aligned pyramid
    // first space is print. there will be hight - row space.
    for (int i = 0; i < height - row_level; i++)
    {
        printf(" ");
    }
    // second the brick # is printed which will increase as the row increase.
    for (int i = 0; i < row_level; i++)
    {
        printf("#");
    }
    // to go to next row
    printf("\n");

    // recursive call to print in next row. row is updated to next row.
    row_print(height, row_level + 1);
}

/*
 * Function: get_height
 * --------------------
 * get a valid non negative number. as height cannot be negative height and height not zero.
 * 
 * prompt: char*. text to be display to ask for user for height.
 * 
 * return: int. gives valid not negative number of height*/
int get_height(char *prompt)
{
    int n;
    // ask user again if input is negative, not int or is zero
    do
    {
        n = get_int("%s", prompt);
    } 
    while (n < 1); 
    return n;   
}
