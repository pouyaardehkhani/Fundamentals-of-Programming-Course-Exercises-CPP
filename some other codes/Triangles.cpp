#include <iostream>

using namespace std;

void input(int **matrix, int n, int m);
int findTriangles(int **matrix, int n, int m);

int main() {
	int n, m;
	int** matrix;
	cin >> n >> m;
	matrix = new int* [n];
	for (int i = 0; i < n; ++i)
		matrix[i] = new int[m];
	input(matrix, n, m);
	cout << findTriangles(matrix, n, m);

	for (int i = 0; i < n; ++i)
		delete[] matrix[i];
	delete[] matrix;
}

void input(int **matrix, int n, int m) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> matrix[i][j];
}

int findVertical1s(int **matrix, int n, int x, int y) {
	int count = 0;
	for (int i = 0; i < n; ++i)
		if (i == x)
			continue;
		else if (matrix[i][y] == 1)
			count++;
	return count;
}

int findHorizontal1s(int **matrix, int m, int x, int y) {
	int count = 0;
	for (int i = 0; i < m; ++i)
		if (i == y)
			continue;
		else if (matrix[x][i] == 1)
			count++;
	return count;
}

int findTriangles(int **matrix, int n, int m) {
	int triangles = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j] != 0) {
				int count = findHorizontal1s(matrix, m, i, j);
				count *= findVertical1s(matrix, n, i, j);
				triangles += count;
			}
		}
	return triangles;
}
