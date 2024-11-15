#ifndef LOGIN_HPP
#define LOGIN_HPP
#include "jsonFcn.hpp"
#include "user.hpp"
#include "admin.hpp"
#include "loginAdmin.hpp"
using namespace std;
using json = nlohmann::json;

class Login {
private:
    json users;
    json admins;
    User u;
    Admin a;
    string username;
    string password;
    bool loggedIn = false;
    bool quit = false;
public:
    Login();
    ~Login();
    bool adminCheck(string& username, string& password);
    bool userCheck(string& username, string& password);
    void takeLoginCred();
    bool userLoggedIn() const;
    bool userHasQuit() const;
};
#endif