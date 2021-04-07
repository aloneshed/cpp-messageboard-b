#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace ariel;
using namespace std;


void Board::post(unsigned int row, unsigned int column, Direction direction, const string &message)
{
    unsigned int length = message.size();

    if (!init_flag && length != 0)
    {
        min_row = row;
        max_row = row;
        min_col = column;
        max_col = column;

        init_flag = true;
    }
    else
    {
        if (min_row > row)
        {
            min_row = row;
        }

        if (min_col > column)
        {
            min_col = column;
        }
    }

    if (direction == Direction::Vertical)
    {
        if (max_row < row + length)
        {
            max_row = row + length - 1;
        }
        for (unsigned long i = 0; i < length; i++)
        {
            board[row++][column] = message.at(i);
        }
    }
    else
    {
        if (max_col < column + length)
        {
            max_col = column + length - 1;
        }
        for (unsigned long i = 0; i < length; i++)
        {
            board[row][column++] = message.at(i);
        }
    }
}

string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length)
{
    string output;
    for (unsigned int i = 0; i < length; i++)
    {
        if (board[row][column] != 0) 
        {
            output += board[row][column];
        }
        else 
        {
            output += '_';
        }
        if (direction == Direction::Horizontal) 
        {
            column++;
        }
        else
        {
            row++;
        }
    }
    return output;
    
}

void Board::show()
{
    for (unsigned int i = min_row; i <= max_row; i++)
    {
        cout << i << ":\t";
        for (unsigned int j = min_col; j <= max_col; j++)
        {
            if (board[i][j] != 0)
            {
                cout << board[i][j];
            }
            else
            {
                cout << '_';
            }
        }
        cout << endl;
    }
}
