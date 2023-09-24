#include <iostream>

using namespace std;

long long N;

int main() {
	cin >> N;

	long long sum = 0, num = 1;
	int cnt = 0;

	while (1) {
		sum = sum + num;
		cnt++;
		if (sum > N) {
			cnt--;
			break;
		}
		num++;
	}

	cout << cnt;
	return 0;
}