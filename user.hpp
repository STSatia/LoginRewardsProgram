#ifndef User_HPP
#define User_HPP

#include <iostream>
#include <string>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class User
{
protected:
    string username = "";
    string password = "";
    string oldPassword = "";
    string name = "";
    string answer = "";
    int d = 0;         // Format: dd//mm//yyyy
    int m = 0;
    int y = 0;
    string email = "";
    string phone_number = "";
    string address = ""; 
    string role = "user";
    int walletBalance = 0;
    int loginCounter = 0;

public:

    // "Default" constructor
    User(); 
    // Non-default constructor
    User(int code); 
    User(string username, string password, string name, string dob, string email, string phone_number, string address, string answer);
    ~User();
    User(const User& existing_user);
    void operator=(const User& existing_user);
    // Getters:
    string get_name();
    string get_username();
    string get_password();
    string get_role();
    string get_old_password();
    int get_login_counter();

    // Setters:
    // thought process: setting each of the attributes one by one whenever you're 
    // creating a fresh account.
    // this can help with user input handling for every single attribute,
    // as there are different types of user handling.
    void set_username(string &username);
    void set_password(string &password);
    void set_old_password(string& old_password);
    void set_name(string &name);
    void set_answer(string &answer);
    void set_dob(string &dob);
    void set_email(string &email);
    void set_phone_number(string &phone_number);
    void set_address(string &address);
    void set_login_counter(int& loginCounter);
    // Methods
    void inc_login_counter();
    void print_info();
    void to_json(json& j);
};

#endif
