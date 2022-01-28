#include <iostream>
#include <iomanip>
using namespace std;

void printSquare(int side);

int main() {
    int side;
    cin >> side;
    printSquare(side);
}

void printSquare(int side) {
	char filler = '*';
	for (int i = side; i > 0; --i) {
		if (i == 1 || i == side)
			filler = '*';
		else
			filler = ' ';
		cout << '*' << setw(side - 1) << setfill(filler) << '*';
		cout << endl;
	}
}
