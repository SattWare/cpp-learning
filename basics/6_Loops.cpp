#include <iostream>
#include <limits>
using namespace std;

int main() {
    int start, end;
    int counter = 0;

    while (cout << "Enter starting and ending number (Ascending)\n" &&
          (!(cin >> start >> end) || start > end)) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("clear");
    }

    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) {
            counter++;
            cout << i << " ";
        }
    }
    cout << "\nThere are " << counter << " even numbers in total\n";
}