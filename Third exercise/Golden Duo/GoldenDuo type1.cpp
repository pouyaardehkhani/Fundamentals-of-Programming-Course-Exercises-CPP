#include <iostream>
#include <cmath>
using namespace std;

bool prime(int odd_number);
int findGoldenDuoHead(int limit);

int main() {
    int limit;
    cin >> limit;
    int golden_head = findGoldenDuoHead(limit);
    printf("%d %d", golden_head,
		   (golden_head == -1) ? golden_head : golden_head + 2);
}

int findGoldenDuoHead(int limit) {
	limit = (limit % 2) ? limit : limit - 1;
	for (; limit > 4; limit -= 2) {
		if (prime(limit) && prime(limit - 2))
			return limit - 2;
	}
	return -1;
}

bool prime(int number) {
	for (int i = 2; i <= sqrt(number); ++i)
		if (number % i == 0)
			return false;
	return true;
}
