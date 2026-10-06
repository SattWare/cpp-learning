#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>
using namespace std;

string registeredEmail, registeredPassword, email, password;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool validatePassword(string password) {
    if (password.size() < 8) return false;
    if (!any_of(password.begin(), password.end(), [](unsigned char c) {return isalpha(c);}) ||
        !any_of(password.begin(), password.end(), [](unsigned char c) {return isdigit(c);}) )
        return false;
    return true;
}

bool validateEmail(string email) {
    const int at  = email.find('@'),
              dot = email.find('.');

    if  ((at < 1 || at == email.size() - 1) ||
        (dot == at + 1 || dot == email.size() - 1)) {
            cout << "Invalid email\n";
            return false;
        }
    return true;
}

int main() {
    cout << "============= Auth =============\n";
    while (cout << "Email:    " && (!(cin >> email) || !validateEmail(email))) {
        char option;
        string newPassword, confirmPassword;

        clearInput();
        
    if (registeredEmail != email) {
        cout << "This email is not registered\n"
                "Would you like to register this email?\n"
                "(Other previous registered emails will no longer work)\n"
                "y/n       ", cin >> option;
        if (option == 'y') registeredEmail = email;

        cout << "\033[A\033[2K" "\033[A\033[2K" "\033[A\033[2K" "\033[A\033[2K";

        while (cout << "Enter password:  " && (!(cin >> newPassword) ||
            !validatePassword(newPassword))) {
            clearInput();
            cout << "Password must be\n"
                    "    • 8 digits long\n"
                    "    • Contains both letters and numbers\n";
        }

        bool multipleAttempts = false;
        while   (cout << "Confirm password:  " && (!(cin >> confirmPassword) || confirmPassword != newPassword)) {
            clearInput();
            if (multipleAttempts) cout << "\033[A\033[2K";
            cout << "\033[A\033[2K"
                    "Confirm password does not match\n";
            multipleAttempts = true;
        }

        cout << "\033[A\033[2K" "\033[A\033[2K" "\033[A\033[2K"

        registeredPassword = newPassword;
        }
    }
    while (cout << "Password:    " && (!(cin >> password) || !validatePassword(password))) clearInput()
}
