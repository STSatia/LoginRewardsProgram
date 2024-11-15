#include "admin.hpp"

Admin::Admin() : User() {
    this->role = "admin";
}

Admin::Admin(int code):
User(code) {
    this->role = "admin";
}

