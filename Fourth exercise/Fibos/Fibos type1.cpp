#include <iostream>
#define ELEMENT10 55

using namespace std;

void fibo();
void fibo(int n);
void fibo(int a, int b);

int main() {
	int a, b;
	cin >> a >> b;
	fibo(a, b);
	cout << endl;
	fibo(b);
	cout << endl;
	fibo();
}

int fibbonachi(int n) {
	if (n == 1 || n == 0)
		return 1;
	return fibbonachi(n - 1) + fibbonachi(n - 2);
}

// Another way to implement this function
// was to add a default value for n as `void fibo(int n = ELEMENT10)`
void fibo() { fibo(ELEMENT10); }

void fibo(int n) {
	int fib = 1;
	for (int element = 1; fib <= n; ++element) {
		cout << fib << " ";
		fib = fibbonachi(element);
	}
}

void fibo(int a, int b) {
	int fib = 1;
	for (int element = 1; fib <= b; ++element) {
		if (a <= fib)
			cout << fib << " ";
		fib = fibbonachi(element);
	}
}
