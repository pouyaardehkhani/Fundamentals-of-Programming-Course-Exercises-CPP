#include <iostream>
using namespace std;

void repeat(char symbol, int times);
void printDoubleDiamond(int diameter);

int main() {
	int diameter;
	cin >> diameter;
	printDoubleDiamond(diameter);
}

void printDoubleDiamond(int diameter) {
	int middle_row = (diameter + 1) / 2;
	for (int row = 1; row <= diameter; ++row) {
		int num_spaces = abs(row - middle_row);
		int num_stars = 1 + 2 * (middle_row - 1 - num_spaces);

		repeat(' ', num_spaces);
		repeat('*', num_stars);
		repeat(' ', 2 * num_spaces);
		repeat('*', num_stars);
		cout << endl;
	}
}

void repeat(char symbol, int times) {
	for (; times > 0; --times)
		cout << symbol;
}
