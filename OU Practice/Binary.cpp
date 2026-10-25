#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string baseConversion(string data, int base, int targetBase) {
	switch (targetBase) {
		case 10: {
			int result = 0;
			
			for (int i = 0; i < data.size(); i++) {
				char ch = tolower(data[data.size() - (i + 1)]);
				result += isdigit(ch) ?  (ch - '0') * pow(base, i) : ch - 'a' + 10;
			}
			
			return to_string(result);
		}
		default: {
			if (targetBase < 2) return data;
			if (base != 10) {
				data = baseConversion(data, base, 10);
			}
			
			string result;
			int div = stoi(data), i = 0;
			
			while (div != 0) {
				int remainder = div % targetBase;
				char cha = 'A' + (remainder - 10);
				result = (targetBase == 16 && remainder >= 10)
						    ? cha + result : to_string(remainder) + result;
				div /= targetBase;
				i++;
				
				if (targetBase == 2) {
					if (i % 3 == 0 && base == 8 || 
                        (i % 4 == 0 && base == 16)) {
						result = ' ' + result;
					}
				}
			}
			if (result[0] == ' ') result.erase(0,1);
			return result;
		}
	}
}
	
int main() {
	string number;
	int base, targetBase;
	
	cout << "number  ", cin >> number;
	cout << "base       target base\n ";
	cin >> base, cout << "\033[1A\033[16C";
	cin >> targetBase;
	
	system("clear");
	cout << baseConversion(number, base, targetBase) << endl;
}