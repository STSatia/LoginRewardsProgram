#include "jsonFcn.hpp"

void grab_users(json &users) {
    ifstream f("users.json");

    // Check if empty file.
    f.seekg(0, std::ios::end);
    if (f.tellg() == 0) {
        cout << "File is currently empty, initializing an empty array..." << endl;
        return;
    }

    // Reset pointer back to beginning
    f.seekg(0, std::ios::beg);

    try {
        f >> users;
    } catch (json::parse_error& e) {
        std::cerr << "Error parsing JSON file: " << e.what() << endl;
        users = json::array();
    }
}

void json_to_user(json& user, User& u) {
    string username = user["username"].get<string>();
    u.set_username(username);
    string oldPassword = user["oldPassword"].get<string>();
    u.set_old_password(oldPassword);
    string password = user["password"].get<string>();
    u.set_password(password);
    string name = user["name"].get<string>();
    u.set_name(name);
    string answer = user["answer"].get<string>();
    u.set_answer(answer);
    string dob = user["dob"].get<string>();
    u.set_dob(dob);
    string email = user["email"].get<string>();
    u.set_email(email);
    string phone_number = user["phone_number"].get<string>();
    u.set_phone_number(phone_number);
    string address = user["address"].get<string>();
    u.set_address(address);
    int login_counter = user["login_counter"].get<int>();
    u.set_login_counter(login_counter);
}
void grab_admins(json& admins) {
    ifstream f("admins.json");

    // Check if empty file.
    f.seekg(0, std::ios::end);
    if (f.tellg() == 0) {
        cout << "File is currently empty, initializing an empty array..." << endl;
        return;
    }

    // Reset pointer back to beginning
    f.seekg(0, std::ios::beg);

    try {
        f >> admins;
    } catch (json::parse_error& e) {
        std::cerr << "Error parsing JSON file: " << e.what() << endl;
        admins = json::array();
    }
}

void json_to_admin(json& admin, Admin& a) {
    string username = admin["username"].get<string>();
    a.set_username(username);
    string oldPassword = admin["oldPassword"].get<string>();
    a.set_old_password(oldPassword);
    string password = admin["password"].get<string>();
    a.set_password(password);
    string name = admin["name"].get<string>();
    a.set_name(name);
    string answer = admin["answer"].get<string>();
    a.set_answer(answer);
    string dob = admin["dob"].get<string>();
    a.set_dob(dob);
    string email = admin["email"].get<string>();
    a.set_email(email);
    string phone_number = admin["phone_number"].get<string>();
    a.set_phone_number(phone_number);
    string address = admin["address"].get<string>();
    a.set_address(address);
    int login_counter = admin["login_counter"].get<int>();
    a.set_login_counter(login_counter);
}

void grab_logs(json& logs) {
    ifstream f("transactionLog.json");

    // Check if empty file.
    f.seekg(0, std::ios::end);
    if (f.tellg() == 0) {
        cout << "File is currently empty, initializing an empty array..." << endl;
        return;
    }

    // Reset pointer back to beginning
    f.seekg(0, std::ios::beg);

    try {
        f >> logs;
    } catch (json::parse_error& e) {
        std::cerr << "Error parsing JSON file: " << e.what() << endl;
        logs = json::array();
    }
}

int grab_options(int limit) {
    string option;
    int option_converted = 0;
    do {
        try {
            cin >> option;
            option_converted = stoi(option);
        } catch (invalid_argument& e) {
            cout << "Invalid input. Please enter a valid number." << endl;
        } catch (out_of_range& e) {
            cout << "Invalid input. Please enter a valid number." << endl;
        }

        if (option_converted > limit) {
            cout << "Invalid input. Please enter a valid number." << endl;
        }

    } while (option_converted <= 0);
    return option_converted;
}