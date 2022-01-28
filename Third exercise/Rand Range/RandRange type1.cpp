#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int rand10th();
void sort(int& min, int& max);
double rand(int end);
double rand(int start, int end);
void printRand(int start, int end, int times);

int main() {
	// initializing random seed
	srand(time(NULL));

	const int Times = 5;
	int start, end;
	cin >> start >> end;
	sort(start, end);

	printRand(start, end, Times);
}

void sort(int& min, int& max) {
	if (min > max) {
		int temp = min;
		min = max;
		max = temp;
	}
}

void printRand(int start, int end, int times) {
	for (; times > 0; --times)
		cout << rand(start, end) << ' ';
	cout << '\b';
}

double rand(int start, int end) {
	return start + rand(end - start);
}

double rand(int end) {
	int rand_10th = rand10th();
	int random = rand() % (end * rand_10th);
	return (double) random / rand_10th;
}

int rand10th() {
	int result = 10;
	for (int power = rand() % 6; power > 0; --power)
		result *= 10;
	return result;
}
