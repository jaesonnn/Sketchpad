#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
    Board();
    void penUp();
    void setPenDown();
    void turnRight();
    void turnLeft();
    void movePen();
    void printBoard();
    bool getPenStatus();
    void doCommand(char cmd);

private:
    const static int ARRAY_SIZE = 12;
    char floor[ARRAY_SIZE][ARRAY_SIZE];

    int xPos, yPos;
    int direction;
    bool penDown;

    const static int EAST = 0;
    const static int SOUTH = 1;
    const static int WEST = 2;
    const static int NORTH = 3;

    const static char playerSymbol = 'x';
    const static char clearSymbol = ' ';
};

#endif // BOARD_H
