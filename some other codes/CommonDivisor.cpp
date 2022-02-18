#include<iostream>
#include <iomanip>

using namespace std;

void printCD(int a, int b);

int main() {
    int a, b;
    cin >> a >> b;
    printCD(a, b);
}

bool first_time = true;
bool printDivisor(int divisor, int a, int b) {
	if (a % divisor == 0 && b % divisor == 0) {
		if (!first_time)
			cout << ',';
		cout << setw(10) << divisor;
		first_time = false;
		return true;
	}
	return false;
}

void printCD(int a, int b) {
	int number = 0;
	for (int divisor = min(a, b); divisor > 0; --divisor)
		if (printDivisor(divisor, a, b))
			number++;
	cout << endl << number;
}
