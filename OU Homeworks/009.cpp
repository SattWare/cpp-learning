#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double r;
    int n;

    cout << "Input r, n:  ", cin >> r >> n;
    
    double P = 1/2.0 * n * r * r * sin(2 * M_PI / n);
    cout << "P = " << P << endl;
}