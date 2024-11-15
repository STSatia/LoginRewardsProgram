#include "login.hpp"

Login::Login() {
    grab_users(users);
    grab_admins(admins);
    takeLoginCred();
    if ((adminCheck(this->username, this->password) == false) && (userCheck(this->username, this->password) == false)) {
            cout << "Invalid credentials. Please try again." << endl;
    }
    else if (adminCheck(this->username, this->password)) {
        loggedIn = true;
        LoginAdmin loginAdmin(this->a);

        while (loginAdmin.getChoice() != 10) {
            loginAdmin.Menu();
            int choice = grab_options(10);
            loginAdmin.setChoice(choice);
            loginAdmin.doChoice();
            if (loginAdmin.hasQuit()) {
                quit = true;
                break;
            }
        }
    } 
    else if (userCheck(this->username, this->password)) {
        loggedIn = true;
        LoginUser loginUser(this->u);
        loginUser.firstLoginCheck();

        while (loginUser.getChoice() != 7) {
            loginUser.Menu();
            int choice = grab_options(7);
            loginUser.setChoice(choice);
            loginUser.doChoice();
            if (loginUser.hasQuit()) {
                quit = true;
                break;
            }
        }
    }

    // Backup.
}
Login::~Login() {}

bool Login::adminCheck(string& username, string& password) {
    for (json admin : admins) {
        if (admin["username"] == username && admin["password"] == password) {
            json_to_admin(admin, this->a);
            return true;
        }
    }
    return false;
}

bool Login::userCheck(string& username, string& password) {
    for (json user : users) {
        if (user["username"] == username && user["password"] == password) {
            json_to_user(user, this->u);
            return true;
        }
    }
    return false;
}

void Login::takeLoginCred() {
    cout << "Please type your username: ";
    getline(cin, this->username);
    cout << "Please type your password: ";
    getline(cin, this->password);
}

bool Login::userLoggedIn() const {return loggedIn;}
bool Login::userHasQuit() const {return quit;}