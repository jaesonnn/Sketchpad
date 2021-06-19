#include <iostream>
using namespace std;

#include "user.h"
#include "board.h"

int main(void)
{
    User player;        // creates a User object called player
    Board gameBoard;    // creates a Board object called gameBoard

    char theCommand;    // stores the player's current comman

    do
    {
        // gets a comman using the player object's getCommand function and then assigns it to variable, theCommand
        theCommand = player.getCommand();

        if(theCommand != 'Q') {                 // checks if theCommand is not the quit command, Q
            gameBoard.doCommand(theCommand);    // passes theCommand to the gameBoard to process
        }
    } while(theCommand != 'Q');

    return 0;
}
