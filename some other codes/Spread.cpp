#include <iostream>

using namespace std;

enum State { Current = -1, Healthy = 0, Ill = 1 };

void input(State **matrix, int n, int m);
State checkNeighbors(State **matrix, int n, int y, int x);
void output(State **matrix, int n, int m);

int main() {
	int n, number_of_tests;
	cin >> n >> number_of_tests;
	auto now = new State*[n];
	auto future = new State*[n];
	for (int i = 0; i < n; ++i) {
		now[i] = new State[n];
		future[i] = new State[n];
	}
	input(now, n, n);
	for (int test_no = 0; test_no < number_of_tests; ++test_no){
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				future[i][j] = now[i][j];
				State future_state = checkNeighbors(now, n, i, j);
				if (future_state == Healthy)
					future[i][j] = Healthy;
				else if (future_state == Ill)
					future[i][j] = Ill;
			}
	}

	output(future, n, n);
}

void input(State **matrix, int n, int m) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			int in;
			cin >> in;
			matrix[i][j] = (State)in;
		}
}

bool exceedLimit(int y, int x, int n) {
	return y >= n || x >= n || y < 0 || x < 0;
}

State checkNeighbors(State **matrix, int n, int y, int x) {
	int healthies = 0, ills = 0;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (i == j && i == 0)
				continue;
			else if (!exceedLimit(y + i, x + j, n)) {
				if (matrix[y + i][x + j] == Healthy)
					healthies++;
				else
					ills++;
			}
		}
	}

	if (healthies > ills)
		return Healthy;
	else if (ills > healthies)
		return Ill;
	else
		return Current;
}

void output(State **matrix, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << (int) matrix[i][j] << " ";
		cout << "\n";
	}
}
