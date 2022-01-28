#include <iostream>

#define EVEN 0
#define ODD 1

using namespace std;

void input(int* array, int size);
int calculateSwaps(int* array, int size);

int main() {
	int n;
	cin >> n;
	
	int* array = new int [n];
	input(array, n);
	
	cout << calculateSwaps(array, n);
}

void input(int* array, int size) {
	for (int i = 0; i < size; ++i)
		cin >> array[i];
}

int calculateSwaps(int* array, int size) {
	int count[ ] = {0, 0};
	
	for (int i = 0; i < size; ++i)
		if (array[i] % 2 != i % 2)
			count[i % 2]++;
	
	return (count[EVEN] == count[ODD]) ? count[EVEN] : -1;
}										// or number of odds... no difference
