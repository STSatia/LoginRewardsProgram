#ifndef LOGINADMIN_HPP
#define LOGINADMIN_HPP
#include "loginUser.hpp"
#include "admin.hpp"
#include <vector>

class LoginAdmin : public LoginUser {
private:
    Admin a;
    bool quit = false;
    int choice = 0;
    json users; // Monitoring users.
public: 
    LoginAdmin(Admin &a);
    ~LoginAdmin();

    void Menu();
    void changeMenu();
    void changeName();
    void changePassword();
    void changeEmail();
    void changeAddress();
    void setChoice(int& new_choice);
    void doChoice();
    void doChoiceMenu(User& u);
    void changeNameUser(User& u);
    void changePasswordUser(User& u);
    void changeEmailUser(User& u);
    void changeAddressUser(User& u);
    void printInfo();
    void displayUsers();
    void createNewAccounts();
    void updateAccounts();
    bool hasQuit() const;
};

void update_admin_in_json(Admin& a);
void create_user(User& u);
bool has_request();
#endif