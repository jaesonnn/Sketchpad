#ifndef USER_H
#define USER_H

class User
{
public:
    User();
    char getCommand();

private:
    bool isLegal(char cmd);
    void showMenu();
};

#endif // USER_H
