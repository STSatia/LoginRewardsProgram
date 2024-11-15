#ifndef REGISTER_HPP
#define REGISTER_HPP
#include "user.hpp"
#include "validity.hpp"
#include "jsonFcn.hpp"
#include <fstream>


class Register {
private:
    User u;
    json users;
public:
    Register();
    Register(bool admin); // Registering on the behalf of someone via an admin.
    ~Register();
    void put_users_to_json(json &users, User& u);
};

string askUsername(json& users);
string askPassword();
string askName();
string askAnswer();
string askDob();
string askEmail();
string askPhoneNumber();
string askAddress();
#endif