#include <iostream>
using namespace std;

void repeat(char symbol, int times);
void printDiamond(int middle_row, int width);

int main() {
	int width, prev_middle_row;
	cin >> width >> prev_middle_row;
	printDiamond(prev_middle_row + 1, width);
}

void printDiamond(int middle_row, int width) {
	int diameter = (middle_row * 2) - 1;
	for (int row = 1; row <= diameter; ++row) {
		int num_spaces = abs(row - middle_row);
		int num_elements = 1 + 2 * (middle_row - 1 - num_spaces);

		repeat(' ', num_spaces);
		for (int i = 0; i < num_elements; ++i)
			if (width <= i && i < num_elements - width)
				cout << ' ';
			else
				cout << '*';
		cout << endl;
	}
}

void repeat(char symbol, int times) {
	for (; times > 0; --times)
		cout << symbol;
}
