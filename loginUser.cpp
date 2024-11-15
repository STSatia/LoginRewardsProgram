#include <iostream>
#include "loginUser.hpp"

using namespace std;

// Basically never call it
LoginUser::LoginUser() {}
LoginUser::LoginUser(User &user): u(user){
    cout << "Welcome, " << u.get_name() << "! " << endl;
    u.inc_login_counter();
    update_user_in_json(u);
}

void LoginUser::firstLoginCheck() {
    if (u.get_login_counter() == 1 && u.get_password() == "defaultpassword") {
        cout << "This is the first time you logged in! Please set up your password." << endl;
        cout << "Your default password is: " << u.get_password() << endl;

        while (u.get_old_password() != "defaultpassword") {changePassword();}
    }
}

void LoginUser::changePassword() {
    // Todo: figure out how typing something would make the terminal print * instead of the actual string.
    string oldPassword = "";
    string newPassword = "";
    string password2 = "";
    cout << "Please type your old password: ";
    cin.ignore();
    getline(cin, oldPassword);
    if (oldPassword != u.get_password()) {
        cout << "Your old password is incorrect!" << endl;
        return;
    }

    cout << "Please type your new password: ";
    getline(cin, newPassword);
    if (newPassword == u.get_old_password() || newPassword == u.get_password()) {
        cout << "Your password cannot be the same as your old password!" << endl;
        return;
    }
    if (passwordValidity(newPassword) == false) {
        return;
    }

    cout << "Please type your new password again: ";
    getline(cin, password2);
    if (newPassword != password2) {
        cout << "The new password typed was not the same as the previous one!" << endl;
        return;
    }

    u.set_old_password(oldPassword);
    u.set_password(newPassword);
    update_user_in_json(u);
    cout << "Password changed successfully." << endl;
}

void LoginUser::changeName() {
    string name;
    cout << "Please enter your new name: ";
    cin.ignore();
    getline(cin,name);
    if (!nameValidity(name)) return;
    u.set_name(name);
    update_user_in_json(u);
    cout << "Name changed successfully." << endl;

}

void LoginUser::changeEmail() {
    string email;
    cout << "Please enter your new email: ";
    cin.ignore();
    getline(cin, email);
    if (!emailValidity(email)) return;

    u.set_email(email);
    update_user_in_json(u);
    cout << "Email changed successfully." << endl;
}

void LoginUser::changeAddress() {
    string address;
    cout << "Please enter your new address: ";
    cin.ignore();
    getline(cin, address);
    if (!addressValidity(address)) return;
    u.set_address(address); 
    update_user_in_json(u);
    cout << "Address changed successfully." << endl;
}

void LoginUser::Menu() {
    cout << "What would you like to do? " << endl;
    cout << "1. Change Name" << endl;
    cout << "2. Change Password" << endl;
    cout << "3. Change Email" << endl;
    cout << "4. Change Address" << endl;
    cout << "5. View Wallet Balance" << endl;
    cout << "6. View Transaction Log" << endl;
    cout << "7. Quit" << endl;
}

int LoginUser::getChoice() {
    return this->choice;
}

void LoginUser::setChoice(int& new_choice) {
    this->choice = new_choice;
}

void LoginUser::doChoice() {
    switch (this->choice) {
        case 1:
            changeName();
            break;
        case 2:
            changePassword(); 
            break;
        case 3:
            changeEmail();
            break;
        case 4:
            changeAddress();
            break;
        case 5:
            cout << "Coming Soon! " << endl;
            break;
        case 6:
            cout << "Coming Soon! " << endl;
            break;
        case 7:
            quit = true;
            return;
        default:
            return;
    }
}

void LoginUser::printInfo() {
    this->u.print_info();
}

void update_user_in_json(User& u) {
    json users = json::array();
    grab_users(users);

    for (auto it = users.begin(); it != users.end(); it++) {
        if ((*it)["username"] == u.get_username()) {
            users.erase(it);
            break;
        }
    }

    json user_json;
    u.to_json(user_json);
    users.push_back(user_json);
    ofstream o("users.json");
    o << setw(4) << users << endl;
}

bool LoginUser::hasQuit() const {return quit;}