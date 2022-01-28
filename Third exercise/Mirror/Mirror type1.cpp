#include <iostream>
using namespace std;

int mirror(int number);
void digitPrinter(int number);

int main() {
	const int MIN = 1000, MAX = 99999;
    int number;
    do {
    	cin >> number;
    	if (MIN <= number && number <= MAX) {
    		cout << mirror(number) << endl;
    		digitPrinter(number);
    	} else if (number != 0)
    		cout << "error\n";
    } while(number != 0);
}

int mirror(int number) {
	int result = 0;
	for (; number > 0; number /= 10)
		result = result * 10 + number % 10;
	return result;
}

void digitPrinter(int number) {
	for (int digit; number > 0; number /= 10) {
		digit = number % 10;
		for (int i = digit; i > 0; --i)
			cout << digit;
		cout << endl;
	}
}
