/**
 * \file mario.c
 * \brief
 * draw pyramid of height. the pyramid at the beginning of super mario bros world 1-1.
 */
#include <cs50.h>
#include <stdio.h>

int get_height(char *prompt);
void draw_pyramid(int height);
void row_print(int height, int row_level);
void print_right(int height, int row_level);
void print_left(int height, int row_level);

/**
 * \brief
 * ask user for non zero non negative number as height and draw the pyramid of that height.
 * 
 * \param void
 * 
 * \return 0
 */
int main(void)
{
    int height = get_height("Height: ");
    draw_pyramid(height);
    return 0;
}

/**
 * \brief
 * initilize starting row (first row) from where the pyramid is printed.
 * 
 * \param height (int): height of the pyramid to be print.
 * 
 * \return void
 */
void draw_pyramid(int height)
{
    int starting_row = 1;
    row_print(height, starting_row);
}

/**
 * \brief
 * print each row with a brick as #. recursive function.
 * 
 * \param height (int): height of the pyramid.
 * \param row_level (int): The row that is to be printed
 * 
 * \returns 
 * function is return if the height is less then the low_level as row cannot be greater 
 * then the given height.
 */
void row_print(int height, int row_level)
{
    // height cannot be less then row to be print.
    if (height < row_level)
    {
        return;
    }
    
    // print left part of pyramid
    print_left(height, row_level);

    // print middle part of pyramid
    printf("  ");

    // print right part of pyramid
    print_right(height, row_level);

    // to go to next row
    printf("\n");

    // recursive call to print in next row. row is updated to next row.
    row_print(height, row_level + 1);
}

/**
 * \brief
 * draw the left part of the pyramid with brick #
 * 
 * \param height (int): height of pyramid
 * \param row_level (int): the row that is to be print
 * 
 * \return void
 */
void print_left(int height, int row_level)
{
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
}

/**
 * \brief
 * draw the right part of the pyramid with brick #
 * 
 * \param height (int): height of pyramid
 * \param row_level (int): the row that is to be print
 * 
 * \return void
 */
void print_right(int height, int row_level)
{
    // for every row with height of h the brick 
    // to be printed will be h - (h - row number)
    for (int i = 0; i < height - (height - row_level); i++)
    {
        printf("#");
    }
}

/**
 * \brief
 * get a valid non negative number. as height cannot be negative height and height not zero.
 * 
 * \param prompt (char*): text to be display to ask for user for height.
 * 
 * \return n (int): gives valid not negative number of height
 */
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
