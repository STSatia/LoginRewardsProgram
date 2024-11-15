#ifndef LOGINUSER_HPP
#define LOGINUSER_HPP
#include "user.hpp"
#include "validity.hpp"
#include "jsonFcn.hpp"
#include <fstream>

class LoginUser {
private:
    User u;
    bool quit = false;
    int choice = 0;
public:
    LoginUser();
    LoginUser(User &user);
    void firstLoginCheck();
    void changeName();
    void changePassword();
    void changeEmail();
    void changeAddress();
    void Menu();
    int getChoice();
    void setChoice(int& new_choice);
    void doChoice();
    void printInfo();
    bool hasQuit() const;
    // void exit();
    // bool getQuitVal();
};  

void update_user_in_json(User& u);

#endif