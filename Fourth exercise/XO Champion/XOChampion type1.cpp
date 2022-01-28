#include <iostream>

#define X 'X'
#define O 'O'
#define NONE ' '

#define Xs 0
#define Os 1
#define TIE 2

using namespace std;

inline void getRedundantNewLine();
void getTables(string** tables, int n);
int* champion(string** tables, int n);
char winner(string* table);
char winner(int* scores);
char repeated(string bunch);

int main() {
	int n;
	cin >> n;
	getRedundantNewLine();
	
	auto tables = new string* [n];
	for (int i = 0; i < n; ++i)
		tables[i] = new string [3];
	getTables(tables, n);

	int* scores = champion(tables, n);
	char champ = winner(scores);
	if (champ == NONE)
		champ = 'N';

	printf("X: %d - Ties: %d - O: %d\nChamp: %c",
		   scores[Xs], scores[TIE], scores[Os], champ);
}

inline void getRedundantNewLine() {
	string redundant;
	getline(cin, redundant);
}

void getTables(string** tables, int n) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j)
			getline(cin, tables[i][j]);
}

int* champion(string** tables, int n) {
	auto scores = new int [3] {0, 0, 0};
	for (int i = 0; i < n; ++i)
		switch (winner(tables[i])) {
		case X:
			scores[Xs]++;
				break;
		case O:
			scores[Os]++;
				break;
		case NONE:
			scores[TIE]++;
				break;
		}
	return scores;
}

inline string concatenate(char a, char b, char c) {
	return new char[3] {a, b, c};
}

char winner(string* table) {
	string diameter_decending, diameter_ascending;
	for (int i = 0; i < 3; ++i) {
		char horizontal = repeated(table[i]);
		if (horizontal != NONE)
			return horizontal;
		
		char vertical =
				repeated(concatenate(table[0][i], table[1][i], table[2][i]));
		if (vertical != NONE)
			return vertical;
		
		diameter_ascending += table[i][2 - i];
		diameter_decending += table[i][i];
	}
	char diameter = repeated(diameter_ascending);
	if (diameter != NONE)
		return diameter;
	
	diameter = repeated(diameter_decending);
	return diameter;
}

char repeated(string bunch) {
	char repeated = bunch[0];
	for (char i : bunch)
		if (i != repeated)
			return NONE;
	return repeated;
}

char winner(int* scores) {
	if (scores[Xs] > scores[Os])
		return X;
	else if (scores[Os] > scores[Xs])
		return O;
	return NONE;
}
