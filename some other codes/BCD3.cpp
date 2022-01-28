#include<iostream>
#define uint unsigned int
using namespace std;

uint makeReverseBCD(uint number);

int main() {
	uint n;
	cin >> n;
	cout << makeReverseBCD(n) << endl;
}

uint reverseBinary(uint number) {
	uint result = 0;
	for (uint digits = 4; digits > 0; number /= 2, --digits)
		result = result * 10 + number % 2;
	return result;
}
// using normal operators and uint
// using bitwise operators in the BCD.cpp
uint makeReverseBCD(uint number) {
	uint BCD = 0;
	for (; number > 0; number /= 10)
		BCD = BCD * 10000 + reverseBinary(number % 10 + 3);
	return BCD;
}
