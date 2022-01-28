#include <iostream>

#define SIZE 100
#define SECOND_MAX 1
#define SECOND_MIN 0

using namespace std;

void input(int array[ ], int size);
void sort(int array[ ], int size);
int* find2nds(int array[ ], int size);

int main() {
	int numbers[SIZE];
	input(numbers, SIZE);
	int* seconds = find2nds(numbers, SIZE);
	cout << seconds[SECOND_MAX] << endl
		 << seconds[SECOND_MIN];
}

void input(int array[ ], int size) {
	for (int i = 0; i < size; ++i)
		cin >> array[i];
}

void sort(int array[ ], int size) {
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size - i - 1; ++j)
			if (array[j] > array[j + 1])
				swap(array[j], array[j + 1]);
}

int* find2nds(int array[ ], int size) {
	sort(array, size);
	int* result = new int[2];
	
	for (int i = 1; i < size; ++i)
		if (array[i] != array[i - 1]) {
			result[SECOND_MIN] = array[i];
			break;
		}
	
	for (int i = size - 2; i > 0; --i)
		if (array[i] != array[i + 1]) {
			result[SECOND_MAX] = array[i];
			break;
		}
	
	return result;
}
