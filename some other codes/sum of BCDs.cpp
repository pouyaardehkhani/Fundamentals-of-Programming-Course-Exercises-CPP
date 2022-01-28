#include <iostream>

using namespace std;

string intToS(int n);
int sToInt(string n);
int BCDToInt(string n);
string intToBCD(int n);
string sumBCD(string a, string b);

int main() {
	string a, b;
	cin >> a >> b;
	cout << sumBCD(a, b);
}

string intToS(int n) { // 3 -> 0011
	string result(4, '0');

	for (int digit = 3; digit >= 0; --digit) {
		result[digit] = (n % 2) + '0';
		n /= 2;
	}

	return result;
}

int sToInt(string n) {
	int result = 0;

	for (char digit: n) {
		result *= 2;
		result += digit - '0';
	}

	return result;
}

int BCDToInt(string n) {
	string digits;
	int result = 0;
	for (char digit: n) {
		digits += digit;
		if (digits.length() == 4) {
			result *= 10;
			result += sToInt(digits);
			digits = "";
		}
	}
	return result;
}

string intToBCD(int n) {
	string result;
	for (; n > 0; n /= 10) {
		string cpy = result;
		result = intToS(n % 10);
		result += cpy;
	}
	return result;
}

string sumBCD(string a, string b) {
	int a_ = BCDToInt(a), b_ = BCDToInt(b);
	a_ += b_;
	return intToBCD(a_);
}
