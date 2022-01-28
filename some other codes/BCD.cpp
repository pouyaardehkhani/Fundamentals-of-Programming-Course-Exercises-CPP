#include<iostream>
#define uint unsigned int
using namespace std;

uint makeBCD(uint number);

int main() {
	uint n;
	cin >> n;
	cout << makeBCD(n) << endl;
}

uint reverseBinary(uint number, uint digits) {
	uint result = 0;
	for (; digits > 0; number /= 2, --digits)
		result = result * 10 + (number % 2);
	return result;
}
// using bitwise operators
// using normal operators in the BCD3.cpp
uint makeBCD(uint number) {
	uint i, BCD_ready = 0;
	for (i = 0; number > 0; ++i, number /= 10)
		BCD_ready |= (number % 10) << (4 * i);
	return reverseBinary(BCD_ready, 4 * i);
}
