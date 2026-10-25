#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int r;
    cout << "Input r:  ", cin >> r;
    
    double V = 4/3 * M_PI * r * r * r;
    cout << "V = " << V << endl;
}