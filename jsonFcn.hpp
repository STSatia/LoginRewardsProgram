#ifndef JSONFCN_HPP
#define JSONFCN_HPP

#include <fstream>
#include <iostream>

#include "json.hpp"
#include "admin.hpp"

using namespace std;
using json = nlohmann::json;

void grab_users(json& users);
void json_to_user(json& users, User& u);
void grab_admins(json& admins);
void json_to_admin(json& admins, Admin& a);
void grab_logs(json& logs);
int grab_options(int limit);

#endif