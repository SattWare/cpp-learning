#include <iostream>
using namespace std;

int main() {
    double x;
    cout << "Input x:  ", cin >> x;

    double x2 = x * x,
           x4 = x2 * x2,
           x8 = x4 * x4,
           x9 = x8 * x;
    
    cout << "x9 = " << x9 << endl;
}