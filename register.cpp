#include "register.hpp" 

Register::Register() {
    grab_users(users);
    string username = askUsername(this->users);
    u.set_username(username);
    string password = askPassword();
    u.set_password(password);
    string name = askName();
    u.set_name(name);
    string answer = askAnswer();
    u.set_answer(answer);
    string dob = askDob();
    u.set_dob(dob);
    string email = askEmail();
    u.set_email(email);
    string phoneNumber = askPhoneNumber();
    u.set_phone_number(phoneNumber);
    string address = askAddress();
    u.set_address(address);

    put_users_to_json(this->users, this->u);
    cout << "User registered successfully." << endl;
} 

Register::~Register() {}

string askUsername(json& users) {
    string username;
    do {
    cout << "Please enter your desired username: " << endl;
    getline(cin, username);
    } while (usernameValidity(username, users) == false);
    return username;
}
string askPassword() {
    string password;
    do {
    cout << "Please enter your desired password: " << endl;
    getline(cin, password);
    } while (passwordValidity(password) == false);
    return password;
}
string askName() {
    string name;
    do {
    cout << "Please enter your name: " << endl;
    getline(cin, name);
    } while (nameValidity(name) == false);
    return name;
}
string askAnswer() {
    string answer;
    cout << "Security question - What is your favorite animal?\nYour answer:  " << endl;
    getline(cin, answer);
    return answer;
}
string askDob() {
    string dob;
    do {
    cout << "Please enter your date of birth (in DD/MM/YYYY format): " << endl;
    getline(cin, dob);
    } while (dobValidity(dob) == false);
    return dob;
}
string askEmail() {
    string email;
    do {
    cout << "Please enter your email: " << endl;
    getline(cin, email);
    } while (emailValidity(email) == false);
    return email;
}

string askPhoneNumber() {
    string phoneNumber;
    do {
    cout << "Please enter your phone number: " << endl;
    getline(cin, phoneNumber);
    } while (phoneNumValidity(phoneNumber) == false);
    return phoneNumber;
}
string askAddress() {
    string address;
    do {
    cout << "Please enter your address: " << endl;
    getline(cin, address);
    } while (addressValidity(address) == false);
    return address;
}


void Register::put_users_to_json(json &users, User& u) {
    json user_json;
    u.to_json(user_json);
    users.push_back(user_json);
    ofstream o("users.json");
    o << std::setw(4) << users << std::endl;
}