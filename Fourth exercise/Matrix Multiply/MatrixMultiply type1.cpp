#include <iostream>
#define MAX_SIZE 10

using namespace std;

// I didn't have to determine the first dimension's size but I did
void input(int array[MAX_SIZE][MAX_SIZE], int n, int m);
void multiply(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int n, int m, int l);
void print(int array[MAX_SIZE][MAX_SIZE], int n, int m);

int main() {
	int n, m, l;
	int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE];
	
	cin >> n >> m >> l;
	input(matrix1, n, m);
	input(matrix2, m, l);
	
	multiply(matrix1, matrix1, n, m, l);
}

void input(int array[MAX_SIZE][MAX_SIZE], int n, int m) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> array[i][j];
}

void multiply(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int n, int m, int l) {
	int result[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < l; ++j) {
			result[i][j] = 0;
			for (int k = 0; k < m; ++k)
				result[i][j] += matrix1[i][k] * matrix2[k][j];
		}
	
	print(result, n, l);
}

void print(int array[MAX_SIZE][MAX_SIZE], int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << array[i][j] << " ";
		cout << endl;
	}
}
