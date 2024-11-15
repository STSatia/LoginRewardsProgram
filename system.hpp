#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include "jsonFcn.hpp"
#include "register.hpp"
#include "login.hpp"

using json = nlohmann::json;

class System {
private:
    // Basically the two json arrays.
    json users;
    int choice = 0;    
public:
    // The system will have the following: Login and Register.

    // This is to load the 2 json arrays.
    System();
    ~System();
    void firstMenu();
    void userMenu();
    void adminMenu();
    void walletMenu();
    int getChoice();
    void setChoice(int& new_choice);
};


#endif