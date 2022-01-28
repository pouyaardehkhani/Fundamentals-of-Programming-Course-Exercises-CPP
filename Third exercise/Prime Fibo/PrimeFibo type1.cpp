#include <iostream>
#include <cmath>

using namespace std;

void sort(int& min, int& max);
bool prime(int number);
void printPrimes(int min, int max);
void printFib(int min, int max);

int main() {
    int min, max;
    cin >> min >> max;
    sort(min, max);
    printPrimes(min, max);
    printFib(min, max);
}

void sort(int& min, int& max) {
	if (min > max) {
		int temp = min;
		min = max;
		max = temp;
	}
}

void printPrimes(int min, int max) {
	for (min++; min < max; ++min)
		if (prime(min))
			cout << min << " ";
	cout << endl;
}

bool prime(int number) {
	for (int i = 2; i <= sqrt(number); ++i)
		if (number % i == 0)
			return false;
	return true;
}

void printFib(int min, int max) {
	int f1 = 0;
	for (int f2 = 1; f2 < max;) {
		if (min <= f2 && f2 <= max)
			cout << f2 << ' ';
		int temp = f2;
		f2 += f1;
		f1 = temp;
	}
}
