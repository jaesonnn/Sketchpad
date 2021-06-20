/* Author:      Floyd Ack
 * Date:        Sunday, 20 June 2020
 * Github:      https://github.com/jaesonnn
 * Twitter:     https://twitter.com/WellFloyd
 * Facebook:    https://www.facebook.com/jason.ack/
 * Instagram:   https://www.instagram.com/wellfloyd_/
*/

#include "user.h"

#include <iostream>
#include <ctype.h>
using namespace std;

User::User()
{
    showMenu();
}

char User::getCommand()
{
    char cmd;           // the command that will be entered by the user

    while(true)         // keep trying until the user enters an acceptable command
    {
        cout << "\n> "; // prompts the user to enter a command

//        cmd = static_cast<char>(cin.get());     // grabs a single char at a time and assigns it to cmd
        cin >> cmd;
        cmd = toupper(cmd);                     // converts the comman(cmd) to upper-case and then reassigns itself

        // call function isLegal and pass it cmd. isLegal returns true if cmd is a valid command
        if(isLegal(cmd))
        {
            if(cmd == 'M')      // if the command entered is 'M', show the menu and stay in the loop
                showMenu();
            else
                return cmd;     // getting here means the command entered was valid but not 'M'
        }
        else {
            cout << "\n** Illegal command. Type M to see menu.";
        }
    }
}

bool User::isLegal(char cmd)
{
    if(cmd == 'M' || cmd == 'Q' || cmd == '4' || cmd == '8' || cmd == '6' || cmd == '2' || cmd == '5')
        return true;
    else
        return false;
}

void User::showMenu()
{
    cout << "   Please select one of the following options\n"
            "   by pressing the indicated key:\n"
            "\n\t8: Pen up\n"
            "\n\t2: Pen down\n"
            "\n\t4: Turn left\n"
            "\n\t6: Turn right\n"
            "\n\t5: Move\n"
            "\n\tM: Menu\n"
            "\n\tQ: Quit\n";
}
