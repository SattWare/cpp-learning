#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    cout << "Input x1, y1, x2, y2:  ",
    cin >> x1 >> y1 >> x2 >> y2;

    double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "Distance: " << d << endl;
}