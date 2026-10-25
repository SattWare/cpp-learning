#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3;
    cout << "Input x1, y1, x2, y2, x3, y3:  ",
    cin >> x1 >> y1
        >> x2 >> y2
        >> x3 >> y3;

    double AB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)),
           BC = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)),
           CA = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2)),
           P = AB + BC + CA;

    cout << "P = " << P << endl;
}