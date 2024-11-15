#include "system.hpp"
#include <iostream>

using namespace std;

System::System() {
    grab_users(this->users);
    while (choice != 3) {
        firstMenu();
        int des = grab_options(3);
        setChoice(des);
        if (choice == 2) {cin.ignore(); Register r;}
        if (choice == 1) {
            cin.ignore(); 
            Login l;
            if (l.userLoggedIn()) {
                if (l.userHasQuit()) {
                    break;
                }
            }
        }
    }
    cout << "Goodbye! " << endl;
}

System::~System() {}

void System::firstMenu() {
    cout << "Please choose an option: " << endl;
    cout << "1 - Login " << endl;
    cout << "2 - Register" << endl;
    cout << "3 - Quit" << endl;
}

void System::userMenu() {
    
}

int System::getChoice() {
    return this->choice;
}

void System::setChoice(int& new_choice) {
    this->choice = new_choice;
}