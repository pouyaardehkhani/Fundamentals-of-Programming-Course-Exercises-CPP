#include <iostream>

using namespace std;

string base16(int n);

int main() {
	int a;
	cin >> a;
	cout << base16(a);
}

char digit16(int digit) {
	if (digit >= 10)
		return 'A' + digit - 10;
	return '0' + digit;
}

string base16(int n) {
	string result;
	for (; n > 0; n /= 16) {
		string cpy = result;
		result = digit16(n % 16);
		result += cpy;
	}
	return result;
}
