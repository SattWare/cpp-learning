#include <iostream>
using namespace std;

int main() {
    int n, t; int s = 0;
    cin >> n; t = n;

    while (t > 0) {
        s += t % 10;
        t /= 10;
    }

    cout << "Tong cac chu so cua " << n << " la " << s << endl;
}