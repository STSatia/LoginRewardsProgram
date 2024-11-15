#ifndef VALIDITY_HPP
#define VALIDITY_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

bool isWhitespace(char c);
bool usernameValidity(string& username, json& users);
bool passwordValidity(string& password);
bool nameValidity(string& name);
bool dobValidity(string& dob);
bool emailValidity(string& email);
bool phoneNumValidity(string& phone_number);
bool addressValidity(string& address);

#endif