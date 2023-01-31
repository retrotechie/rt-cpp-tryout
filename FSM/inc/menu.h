#ifndef MENU_H
#define MENU_H

#include "./state.h"

#include <iostream>
#include <unistd.h> // For `usleep()`

using namespace std;

class CMenu : public AState // Derived class from abstract `State`
{
public:
    CMenu();

    // `virtual` can only be used inside class definition
    virtual void update() override
    {
        this->render();

        int menuOption;
        cout << "\nWhich number do you choose? ";
        cin >> menuOption;

        if (menuOption == 1 ||
            menuOption == 2 ||
            menuOption == 3 ||
            menuOption == 0)
        {
            this->setNextState(menuOption);
            this->setIsFinished(true);
        }
        else
        {
            cout << "Wrong input, try again !";
        }
    }

    virtual void render() override
    {
        cout << "*―――――――――――――――――――――――――――――――――――――――――――――――――――――――*\n";
        cout << "│                  Finite State Machine                 │\n";
        cout << "*―――――――――――――――――――――――――――――――――――――――――――――――――――――――*\n";
        cout << "│                     1. Menu                           │\n";
        cout << "│                     2. Actions                        │\n";
        cout << "│                     3. About                          │\n";
        cout << "│                     0. Exit                           │\n";
        cout << "*―――――――――――――――――――――――――――――――――――――――――――――――――――――――*\n";
    }
};

#endif // MENU_H
