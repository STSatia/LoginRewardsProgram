#include "loginAdmin.hpp"

LoginAdmin::LoginAdmin(Admin &a): a(a){
    cout << "Welcome, " << a.get_name() << "! " << endl;
    grab_users(users);
}

LoginAdmin::~LoginAdmin() {}

void LoginAdmin::changeName() {
    string name;
    cout << "Please enter your new name: ";
    cin.ignore();
    getline(cin, name);
    if (!nameValidity(name)) return;
    a.set_name(name);
    update_admin_in_json(a);
    cout << "Name changed successfully." << endl;
}

void LoginAdmin::changePassword() {
    string oldPassword = "";
    string newPassword = "";
    string password2 = "";
    cout << "Please type your old password: ";
    cin.ignore();
    getline(cin, oldPassword);
    if (oldPassword != a.get_password()) {
        cout << "Your old password is incorrect!" << endl;
        return;
    }

    cout << "Please type your new password: ";
    getline(cin, newPassword);
    if (newPassword == a.get_old_password() || newPassword == a.get_password()) {
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

    a.set_old_password(oldPassword);
    a.set_password(newPassword);
    update_admin_in_json(a);
    cout << "Password changed successfully." << endl;
}

void LoginAdmin::changeEmail() {
    string email;
    cout << "Please enter your new email: ";
    cin.ignore();
    getline(cin, email);
    if (!emailValidity(email)) return;

    a.set_email(email);
    update_admin_in_json(a);
    cout << "Email changed successfully." << endl;
}

void LoginAdmin::changeAddress() {
    string address;
    cout << "Please enter your new address: ";
    cin.ignore();
    getline(cin, address);
    if (!addressValidity(address)) return;
    a.set_address(address); 
    update_admin_in_json(a);
    cout << "Address changed successfully." << endl;
}

void LoginAdmin::printInfo() {
    this->a.print_info();
}

void LoginAdmin::displayUsers() {
    grab_users(this->users);
    for (json user : users) {
        User u;
        json_to_user(user, u);
        u.print_info();
        cout << "---------------------" << endl;
    }
}

void LoginAdmin::createNewAccounts() {
    if (has_request()) {
        User u;
        create_user(u);
        json user_json;
        u.to_json(user_json);
        users.push_back(user_json);
        ofstream o("users.json");
        o << setw(4) << users << endl;
        cout << "User created successfully." << endl;
    } else {
        cout << "No requests found at this moment." << endl;
    }

}

void LoginAdmin::updateAccounts() {
    // Find the user that they want to update
    string desiredUsername;
    bool found = false;
    User u;
    cout << "Give the username of the desired account you wanted to change: " << endl;
    cin.ignore();
    getline(cin, desiredUsername);
    for (json user : users) {
        if (user["username"] == desiredUsername) {
            json_to_user(user, u);
            found = true;
            break;
        }
    }
    if (found) {
        changeMenu();
        int choice = grab_options(5);
        setChoice(choice);
        doChoiceMenu(u);
        // Change and throw back in json.
    } else {
        cout << "User not found. Please try again." << endl;
    }

}

void LoginAdmin::doChoice() {
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
            displayUsers();
            break;
        case 6:
            updateAccounts();
            break;
        case 7:
            createNewAccounts();
            break;
        case 8:
            cout << "Coming soon!" << endl;
            break;
        case 9:
            cout << "Coming soon!" << endl;
            break;
        case 10:
            quit = true;
            return;
        default:
            return;
    }
}

bool LoginAdmin::hasQuit() const {return quit;}

void LoginAdmin::setChoice(int& new_choice) {
    this->choice = new_choice;
}
void LoginAdmin::doChoiceMenu(User& u) {
    switch (this->choice) {
        case 1:
            changeNameUser(u);
            break;
        case 2:
            changePasswordUser(u);
            break;
        case 3:
            changeEmailUser(u);
            break;
        case 4:
            changeAddressUser(u);
            break;
        case 5:
            return;
        default:
            return;
    }
}

void LoginAdmin::changeNameUser(User& u) {
    string name;
    cin.ignore();
    cout << "Please type in the new name for user: " << endl;
    getline(cin, name);
    if (nameValidity(name) == false) {
        return;
    }

    u.set_name(name);
    update_user_in_json(u);
    grab_users(users);
    cout << "Name updated successfully." << endl;
}

void LoginAdmin::changePasswordUser(User& u) {
    string password;
    string old_password = u.get_password();
    cin.ignore();
    cout << "Please type in the new password for user: " << endl;
    getline(cin, password);
    if (passwordValidity(password) == false) {
        return;
    }

    u.set_old_password(old_password);
    u.set_password(password);
    update_user_in_json(u);
    grab_users(users);
    cout << "Password updated successfully." << endl;
}

void LoginAdmin::changeEmailUser(User& u) {
    string email;
    cout << "Please type in the new email for user: " << endl;
    cin.ignore();
    getline(cin, email);
    if (!emailValidity(email)) return;

    u.set_email(email);
    update_user_in_json(u);
    grab_users(users);
    cout << "Email updated successfully." << endl;
}

void LoginAdmin::changeAddressUser(User& u) {
    string address;
    cout << "Please type in the new address for user: " << endl;
    cin.ignore();
    getline(cin, address);
    if (!addressValidity(address)) return;
    u.set_address(address); 
    update_user_in_json(u);
    grab_users(users);
    cout << "Address updated successfully." << endl;
}
void LoginAdmin::Menu() {
    cout << "What would you like to do? " << endl;
    cout << "1. Change Name" << endl;
    cout << "2. Change Password" << endl;
    cout << "3. Change Email" << endl;
    cout << "4. Change Address" << endl;
    cout << "5. Display users" << endl;
    cout << "6. Update user's account information" << endl;
    cout << "7. Create new account" << endl;
    cout << "8. View Wallet Balance" << endl;
    cout << "9. View Transaction Log" << endl;
    cout << "10. Quit" << endl;
}

void LoginAdmin::changeMenu() {
    cout << "Which data would you like to change? " << endl;
    cout << "1. Change Name" << endl;
    cout << "2. Change Password" << endl;
    cout << "3. Change Email" << endl;
    cout << "4. Change Address" << endl;
    cout << "5. Cancel" << endl;
}
void update_admin_in_json(Admin& a) {
    json admins = json::array();
    grab_admins(admins);

    for (auto it = admins.begin(); it != admins.end(); it++) {
        if ((*it)["username"] == a.get_username()) {
            admins.erase(it);
            break;
        }
    }

    json admin_json;
    a.to_json(admin_json);
    admins.push_back(admin_json);
    ofstream o("admins.json");
    o << setw(4) << admins << endl;
}

void create_user(User& u) {
    ifstream inFile("request.txt");
    string arr[8];
    for (int i = 0; i < 8; i++) {
        if (i == 1) {arr[i] = ""; continue;}
        getline(inFile, arr[i]);
    }
    string line;
    vector<string> remaining_lines;

    while (getline(inFile, line)) {
        remaining_lines.push_back(line);
    }
    inFile.close();

    ofstream outFile("request.txt");
    for (string& l : remaining_lines) {
        outFile << l << endl;
    }
    outFile.close();
    
    u = User(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7]);
}
bool has_request() {
    ifstream inFile("request.txt");
    if (!inFile.is_open()) {
        cout << "Error: cannot open file" << endl;
        return false;
    }
    string line = "";
    int counter = 0;
    while (getline(inFile, line)) {
        counter += 1;
    }
    if (counter % 7 != 0) {
        cout << "Error: no valid request found" << endl;
        return false;
    }
    
    if (counter == 0)   return false;
    
    cout << "Requests found." << endl;
    return true;
}