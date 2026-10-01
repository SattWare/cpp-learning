#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double BMI,  weight, height;
    
    cout << "========== BMI Calculator ==========\n"
            "Please enter your Weight (Kg): ", cin >> weight,
    cout << "Please enter your Height  (m): ", cin >> height,
    cout << "########### Your BMI is ############\n"
         << "               " << weight/pow(height, 2) << endl;

    return 0;
}