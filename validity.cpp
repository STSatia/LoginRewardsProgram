#include <cctype>
#include "validity.hpp"
bool isWhitespace(char c) {
    return (c == ' ' || c == 9 || c == 13 || c == 11 || c == 12);
}

bool usernameValidity(string &username, json& users) {
    transform(username.begin(), username.end(), username.begin(), [](unsigned char c) { return std::tolower(c); });
    if (username.length() > 64) {
        cout << "Your username is too long!" << endl;
        return false;
    }

    for (json user : users) {
        if (user["username"] == username) {
            cout << "This username has already been taken!" << endl;
            return false;
        }
    }
    for (char c : username) {
        if (!isalnum(c)) {
            cout << "The username should not contain special characters or spaces!" << endl;
            return false;
        }
    }
    return true;
}
bool passwordValidity(string& password) {
    bool lowerCase = false;
    bool upperCase = false;
    bool number = false;
    bool specialChar = false;

    if (password.length() < 8) {
        cout << "The password is too short!" << endl;
        return false;
    }
    if (password.length() > 128) {
        cout << "The password is too long!" << endl;
        return false;
    }
    for (int i = 0; i < password.length(); i++) {
        if (password[i] > 122 && password[i] < 127) {specialChar = true; continue;}
        if (password[i] > 96) {lowerCase = true; continue;}
        if (password[i] > 90) {specialChar = true; continue;}
        if (password[i] > 64) {upperCase = true; continue;}
        if (password[i] > 57) {specialChar = true; continue;}
        if (password[i] > 47) {number = true; continue;}
        if (password[i] > 32) {specialChar = true;}
    }
    
    if (!(lowerCase && upperCase && number && specialChar)) {   
        cout << "The password doesn't meet all of the requirements!" << endl;
        return false;
    }
    return true;
}

bool nameValidity(string& name) {
    if (name.length() > 64) {
        cout << "The name input was too long." << endl;
        return false;}
    for (int i = 0; i < name.length(); i++) {
        if (!isalpha(name[i]) && !isWhitespace(name[i])) {
            cout << "The name cannot have numbers or special characters" << endl;
            return false;
        }
    }
    return true;
}

bool emailValidity(string& email) {
    if (email.length() > 64) {
        cout << "The email inputted is too long." << endl;
        return false;
    }
    int atCounter = 0;
    int dotCounter = 0;
    bool valid = true;
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') {atCounter += 1; continue;}
        if (email[i] == '.') {dotCounter += 1; continue;}
        if ((email[i] > 122 && email[i] < 127) || (email[i] > 90 && email[i] < 97) || (email[i] > 57 && email[i] < 64) || (email[i] == 47) || (email[i] > 32 && email[i] < 47)
            || (email[i] == 32) || (isWhitespace(email[i]))) {
            cout << "The email cannot have special characters." << endl;
            valid = false;
            break;
        }
    }
    if (atCounter != 1 || dotCounter < 1) {cout << "Invalid formatting, please try again." << endl; valid = false;
    }
    return valid;
}

bool dobValidity(string& dob) {
    // TODO: Implement more stuff so that it really truncates the dates within the corresponding months.
    if ((dob.length() != 10) || (dob[2] != '/') || (dob[5] != '/')) {
        cout << "Invalid input. Please type within the format of DD/MM/YYYY" << endl;
        return false;
    }
    for (char c : dob) {
        if (!isdigit(c) && c != '/') {
            cout << "Your date of birth cannot contain anything but numbers!" << endl;
            cout << "Please type within the format of DD/MM/YYYY" << endl;
            return false;
        }
    }
    dob[2] = ' ';
    dob[5] = ' ';
    stringstream ss(dob);
    int day, month, year;
    ss >> day >> month >> year;
    if (day <= 0 || day > 31) {cout << "Invalid day. Please try again." << endl; return false;}
    if (month <= 0 || month > 12) {cout << "Invalid month. Please try again." << endl; return false;}
    if (year <= 1900 || year > 2024) {cout << "Invalid year. Please try again." << endl; return false;}
    return true;
}

bool phoneNumValidity(string& phone_number) {
    if (phone_number.length() < 10 || phone_number.length() > 11) {
        cout << "The phone number can only be within 10-11 digits." << endl;
        return false;
    }
    for (char c : phone_number) {
        if (!isdigit(c)) {
            cout << "The phone number must only contain numbers." << endl;
            return false;
        }
    }
    return true;
}
bool addressValidity(string& address) {
    if (address.length() > 128) {cout << "The address typed in is too long!" << endl; return false;} 
    for (int i = 0; i < address.length(); i++) {
        if (!isalnum(address[i]) && !isspace(address[i]) && address[i] != ',' && address[i] != '.' && address[i] != '-' && address[i] != '#' && address[i] != '/') {
            std::cout << "The address contains invalid characters!" << std::endl;
            return false;
        }
    }
    return true;
}