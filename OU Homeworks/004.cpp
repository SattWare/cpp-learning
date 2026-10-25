#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double r;
    cout << "Input r:  ", cin >> r;
    
    double s = 4 * M_PI * r * r;
    cout << "s = " << s << endl;
}