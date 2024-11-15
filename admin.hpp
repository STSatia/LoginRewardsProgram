#ifndef ADMIN_HPP
#define ADMIN_HPP
#include "user.hpp"

class Admin : public User {
private:
    json users;
public:
    Admin();
    Admin(int code);
    // Getters:

    // Create new accounts will be within LoginAdmin instead.
    // Update account information would just set the user's attribute as an admin.
};
#endif