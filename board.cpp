/* Author:      Floyd Ack
 * Date:        Sunday, 20 June 2020
 * Github:      https://github.com/jaesonnn
 * Twitter:     https://twitter.com/WellFloyd
 * Facebook:    https://www.facebook.com/jason.ack/
 * Instagram:   https://www.instagram.com/wellfloyd_/
*/

#include "board.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

Board::Board()
{
    xPos = 0;           // represents the player's current position in the row
    yPos = 0;           // represents the player's current position in the column

    penDown = false;
    direction = EAST;   // direction is set to EAST which has a value of 0

    for(int row=0; row<ARRAY_SIZE; row++)
        for(int col=0; col<ARRAY_SIZE; col++)
            floor[row][col] = clearSymbol;      // all values of the 2d array are given a NULL value
}

// determines if then pen is up
void Board::penUp()
{
    penDown = false;
}

// determines if the pen is down
void Board::setPenDown()
{
    penDown = true;
}

// increments the value of direction everytime function turnRight() is called
void Board::turnRight()
{
    if(direction == EAST)
        direction = SOUTH;
    else if(direction == SOUTH)
        direction = WEST;
    else if(direction == WEST)
        direction == NORTH;
    else if(direction == NORTH)
        direction == EAST;
}

// decrements the value of direction everytime function turnLeft() is called
void Board::turnLeft()
{
    if(direction == NORTH)
        direction = WEST;
    else if(direction == WEST)
        direction = SOUTH;
    else if(direction == SOUTH)
        direction = EAST;
    else if(direction == EAST)
        direction = NORTH;
}

// moves one space in the direction that is currently being pointed in
void Board::movePen()
{
    if(direction == EAST)
    {
        xPos++;         // incremented because EAST represents the positives on the x-axis

        // prevents the player to move off the right side of the board
        if(xPos == ARRAY_SIZE)
            xPos = 0;

        // draws an 'x' if the pen is set down
        if(getPenStatus())
            floor[yPos][xPos] = playerSymbol;

        printBoard();
    }
    else if(direction == NORTH)
    {
        yPos++;         // incremented because NORTH represents the positives on the y-axis

        // prevents the player to move off the upper side of the board
        if(yPos == ARRAY_SIZE)
            yPos = 0;

        if(getPenStatus())
            floor[yPos][xPos] = playerSymbol;

        printBoard();
    }
    else if(direction == WEST)
    {
        xPos--;         // decremented because WEST represents the negatives on the x-axis

        if(xPos < 0)
            xPos = (ARRAY_SIZE - 1);

        if(getPenStatus())
            floor[yPos][xPos] = playerSymbol;

        printBoard();
    }
    else if(direction == SOUTH)
    {
        yPos--;         // decremented because SOUTH represents the negatives on the y-axis

        if(yPos < 0)
            yPos = (ARRAY_SIZE - 1);

        if(getPenStatus())
            floor[yPos][xPos] = playerSymbol;

        printBoard();
    }
}

void Board::printBoard()
{
    system("cls");    // clears the screen

    // arrows are printed on the screen showing the current direction
    if(direction == NORTH)
        cout << "|\n|\nS\n\n";
    else if(direction == EAST)
        cout << "-----> W\n\n";
    else if(direction == SOUTH)
        cout << "N\n^\n|\n|\n";
    else
        cout << "E <-----\n\n";

    for(int i=0; i<ARRAY_SIZE; i++)
    {
        // ARRAY_SIZE(12) * NORTH is for the grid's horizontal line
        for(int g=0; g<(ARRAY_SIZE * NORTH + 1); g++)
            cout << "-";

        cout << "\n|";                      // a vertical line is printed at the beginning

        for(int j=0; j<ARRAY_SIZE; j++) {
            cout << floor[i][j] << " |";    // vertical lines are printed all throughout
        }
        cout << "\n";
    }

    // ARRAY_SIZE(12) * NORTH is for the grid's horizontal line
    for(int k=0; k<(ARRAY_SIZE * NORTH + 1); k++)
        cout << "-";
}

// returns the current value of penDown which will either be true or false
bool Board::getPenStatus()
{
    return penDown;
}

// calls appropriate functions that corresponds to the command passed into this function
void Board::doCommand(char cmd)
{
    switch(cmd)
    {
        case '8':
            penUp();
            break;
        case '2':
            setPenDown();
            break;
        case '4':
            turnLeft();
            break;
        case '6':
            turnRight();
            break;
        case '5':
            movePen();
            break;
    }
}
