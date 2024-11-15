#include "user.hpp"


// Default constructor: Nothing.
User::User() {}

// Admin constructor:
User::User(int code) {
    if (code == 1) {
        username = "admin01";
        password = "NTC2002";
        oldPassword = "admin01";
        name = "Nguyen Tam Chien";
        d = 26;
        m = 7;
        y = 2002;
        email = "n20dcpt008@ptithcm.edu.vn";
        address = "Go Vap - TPHCM";
        walletBalance = 10000;
        loginCounter = 26072002;
    } else {
        username = "admin02";
        password = "THC2005";
        oldPassword = "admin02";
        name = "Tran Huu Chung";
        d = 13;
        m = 12;
        y = 2005;
        email = "n23dcdk008@ptithcm.edu.vn";
        address = "Binh Tan - TPHCM";
        walletBalance = 10000;
        loginCounter = 13122005;
    }
}


// User constructor
// For creating a username used by an admin.
User::User(string username, string password, string name, string dob, string email, string phone_number, string address, string answer) {
        this->username = username;
        this->password = password;
        if (password == "") this->password = "defaultpassword";
        this->name = name;
        this->answer = answer;
        this->d = stoi(dob.substr(0, 2));
        this->m = stoi(dob.substr(3, 2));
        this->y = stoi(dob.substr(6, 4));
        this->email = email;
        this->address = address;
        this->phone_number = phone_number;
        this->walletBalance = 0;
        this->loginCounter = 0;
}

User::~User() {}

// CC and AOO - idk if i need this if I don't use dynamic mem

User::User(const User& existing_user) {
    this->username = existing_user.username;
    this->password = existing_user.password;
    this->oldPassword = existing_user.oldPassword;
    this->name = existing_user.name;
    this->answer = existing_user.answer;
    this->d = existing_user.d;
    this->m = existing_user.m;
    this->y = existing_user.y;
    this->email = existing_user.email;
    this->phone_number = existing_user.phone_number;
    this->address = existing_user.address;
    this->role = existing_user.role;
    this->walletBalance = existing_user.walletBalance;
    this->loginCounter = existing_user.loginCounter;
}

void User::operator=(const User& existing_user) {
    if (this == &existing_user) {
        return;
    }
    this->username = existing_user.username;
    this->password = existing_user.password;
    this->oldPassword = existing_user.oldPassword;
    this->name = existing_user.name;
    this->answer = existing_user.answer;
    this->d = existing_user.d;
    this->m = existing_user.m;
    this->y = existing_user.y;
    this->email = existing_user.email;
    this->phone_number = existing_user.phone_number;
    this->address = existing_user.address;
    this->role = existing_user.role;
    this->walletBalance = existing_user.walletBalance;
    this->loginCounter = existing_user.loginCounter;
}

// Getters and incrementors:

string User::get_name() {return this->name;}
string User::get_username() {return this->username;}
string User::get_old_password() {return this->oldPassword;}
string User::get_password() {return this->password;}
string User::get_role() {return this->role;}
int User::get_login_counter() {return loginCounter;}
void User::inc_login_counter() {loginCounter += 1;}


// Setters:
void User::set_username(string &username) {this->username = username;}
void User::set_name(string &name) {this->name = name;}
void User::set_answer(string &answer) {this->answer = answer;}
void User::set_email(string &email) {this->email = email;}
void User::set_phone_number(string &phone_number) {this->phone_number = phone_number;}
void User::set_address(string &address) {this->address = address;}
void User::set_dob(string &dob) {
    this->d = stoi(dob.substr(0, 2));
    this->m = stoi(dob.substr(3, 2));
    this->y = stoi(dob.substr(6, 4));
}
void User::set_password(string &password) {
    // TODO: Hash the password.
    this->password = password;
}

void User::set_old_password(string& old_password) {
    this->oldPassword = old_password;
}

void User::set_login_counter(int& LoginCounter) {
    this->loginCounter = LoginCounter;
}

void User::print_info() {
    cout << "Username: " << this->username << endl;
    cout << "Password: " << this->password << endl;
    cout << "Old Password: " << this->oldPassword << endl;
    cout << "Name: " << this->name << endl;
    cout << "Answer: " << this->answer << endl;
    cout << "Day: " << this->d << endl;
    cout << "Month: " << this->m << endl;
    cout << "Year: " << this->y << endl;
    cout << "Email: " << this->email << endl;
    cout << "Phone number: " << this->phone_number << endl;
    cout << "Address: " << this->address << endl;
    cout << "Role: " << this->role << endl;
    cout << "Login Counter: " << this->loginCounter << endl;
}

void User::to_json(json& j) {
    std::ostringstream dob_stream;
    dob_stream << (d < 10 ? "0" : "") << d << "/"
               << (m < 10 ? "0" : "") << m << "/"
               << y;
    std::string dob = dob_stream.str();
    j = json {
        {"username", this->username},
        {"password", this->password},
        {"oldPassword", this->oldPassword},
        {"name", this->name},
        {"answer", this->answer},
        {"dob", dob},
        {"email", this->email},
        {"phone_number", this->phone_number},
        {"address", this->address},
        {"login_counter", this->loginCounter}
    };
}