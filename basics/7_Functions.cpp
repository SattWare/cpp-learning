#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>
using namespace std;

string registeredEmail, registeredPassword, email, password;
int lineCounter = 0;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void clearLine() {
    for (int i = 1; i <= lineCounter; i++) {
        cout << "\033[A\033[2K";
    }
} // Functions Overload


void clearLine(int amount) {
    for (int i = 1; i <= amount; i++) {
        cout << "\033[A\033[2K";
        lineCounter--;
    }
}

int validatePassword(string password) {
    int invalid = 3;
    bool valid = true;
    if (password.size() < 8) { invalid = 1; valid = false; }
    if ((!any_of(password.begin(), password.end(), [](unsigned char c) {return isalpha(c);})) ||
       (!any_of(password.begin(), password.end(), [](unsigned char c) {return isdigit(c);}))) { invalid = invalid == 3 ? 2 : 3; valid = false; }
    return !valid ? invalid : 0;
}

bool validateEmail(string email) {
    const int at  = email.find('@'),
              dot = email.find('.');

    if  (at < 1 || at == email.size() - 1 ||
        dot < 1 || dot == at + 1 || dot == email.size() - 1) {
            cout << "Invalid email\n";
            lineCounter++;
            return false;
        }
    return true;
}

int main() {
    bool validEmail = false; 
    cout << "============= Auth =============\n";
    while (cout << "Email:    " && (!(cin >> email) || !validEmail)) {
        char option;
        string newPassword, confirmPassword;
        bool valid = validateEmail(email);

        lineCounter++;
        clearInput();

        if (valid && registeredEmail == email) {
            validEmail = true; break;
        }
        else if (valid && registeredEmail != email) {
            cout << "This email is not registered\n"
                    "Would you like to register this email?\n"
                    "(Other previous registered emails will no longer work)\n"
                    "y/n       ", cin >> option;
            lineCounter += 4;
            if (option == 'y') {
                clearLine(4);
                bool validPassword = false;
                bool multipleAttempts = false;

                while (cout << "Set a password:  " && (!(cin >> newPassword) || !validPassword)) {
                    int invalid = validatePassword(newPassword);
                    clearInput(); lineCounter++;
                    if (multipleAttempts) clearLine(4);
                    if (!invalid) { validPassword = true; break; clearLine(4); }


                    cout << "Password must be\n"; lineCounter++;
                    cout << (invalid == 1 || invalid == 3 ? "  ❌ • 8 digits long\n" : "  ✅ • 8 digits long\n");
                    cout << (invalid == 2 || invalid == 3 ? "  ❌ • Contains both letters and numbers\n" : "  ✅ • Contains both letters and numbers\n");
                    
                    multipleAttempts = true;
                }

                multipleAttempts = false;

                while (cout << "Confirm password:  " && (!(cin >> confirmPassword) || confirmPassword != newPassword)) {
                    if (multipleAttempts) clearLine(1);
                    clearLine(1); clearInput();
                    lineCounter += 2;

                    cout << "Confirm password does not match\n";

                    multipleAttempts = true;
                }

                clearLine();

                cout << email << " Successfully registered ✅\n\n";

                registeredEmail = email;
                registeredPassword = newPassword;
                valid = true;
            } else clearLine();
        }
    }
    while (cout << "Password:    " && (!(cin >> password || password != registeredPassword))) {
        clearInput(); clearLine(2);
        cout << "Incorrect password\n";
    }
    
    cout << "=========== Logged in ==========\n"
            "Welcome to my C++ Journey!\n";
}
