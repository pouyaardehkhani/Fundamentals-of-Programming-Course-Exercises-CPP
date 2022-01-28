#include <iostream>

using namespace std;

void input(int* array, int size);
int* turn(int* array, int size, int turned);
void print(int* array, int size);

int main() {
	int n, d;
	cin >> n >> d;
	int* array = new int [n];
	input(array, n);

	array = turn(array, n, d);
	print(array, n);
}

void input(int* array, int size) {
	for (int i = 0; i < size; ++i)
		cin >> array[i];
}

// many of you've just printed it out of order
// so it looks the same and is an acceptable approach,... I guess
int* turn(int* array, int size, int turned) {
	int* answer = new int [size];
	turned %= size;
	for (int i = 0; i < size; ++i) {
		if (i - turned < 0)
			answer[size + (i - turned)] = array[i];
		else
			answer[i - turned] = array[i];
	}
	return answer;
}

void print(int* array, int size) {
	bool first = true;
	for (int i = 0; i < size; ++i)
		if (first) {
			cout << array[i];
			first = false;
		} else
			printf(",%d", array[i]);
}
