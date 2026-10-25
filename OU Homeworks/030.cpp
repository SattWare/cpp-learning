#include <iostream>
using namespace std;

int main() {
    int n;
    double S = 0;
    int i = 1;

    cout << "Input n:  ", cin >> n;

    while (i <= n) {
        S += 1.0/(2 * i);
        i++; 
    }

    cout << "S = " << S << endl;
}