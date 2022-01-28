#include <iostream>

using namespace std;

void sort(int& min, int& max);
void fibo(int min, int max);
void fibo(int max);
void fibo();

int f1 = 0 ,f2 = 1;

int main() {
	int a, b;
	cin >> a >> b;
	sort(a, b);
	
	fibo(a, b); cout << '\n';
	fibo(b);    cout << '\n';
	fibo();
}

void sort(int & min, int & max) {
	if (min > max) {
		int temp = min;
		min = max;
		max = temp;
	}
}

void fibo(int min, int max) {
	if (min <= f2 && f2 <= max)
		cout << f2 << " ";
	
	int temp = f2;
	f2 += f1;
	f1 = temp;
	
	if (f2 <= max)
		fibo(min, max);
	else {
		f1 = 0;
		f2 = 1;
	}
}

void fibo(int max) { fibo(1, max); }
void fibo() { fibo(1, 55); }
