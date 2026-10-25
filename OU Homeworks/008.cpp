#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double r;
    int n;

    cout << "Input r, n:  ", cin >> r >> n;
    
    double P = 2 * n * r * sin(M_PI / n);
    cout << "P = " << P << endl;
}