#include <iostream>
#include <string>
using namespace std;

string name;

int main(){
    int option;
    cout << "Whats your name? ", cin >> name;
    cout << "=========== Dialogue ===========\n"
            "1. Hello, what is this program?\n"
            "2. How are you doing so far?\n"
            "3. Who are you?\n",
            cin >> option;
            system("clear");
    if (option == 1) { cout << "Hello " << name << "! This program is my first C++ practice!"; }
    else if (option == 2) { cout << "I'm doing great! " << name << ". How about you?"; }
    else if (option == 3) { cout << "Hi " << name << "! I'm Satt, A learning Software Engineering student. Nice to meet you!"; }
    else { cout << "Welcome to my C++ Journey!"; }
    cout << endl;

    return 0;
}