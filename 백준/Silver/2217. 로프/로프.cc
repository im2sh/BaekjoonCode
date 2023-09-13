#include <iostream>
#include <algorithm>
using namespace std;
int n;
int input[100000];
int ret;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);
	for (int i = 0; i < n; i++) {
		ret = max(ret, (n - i)*input[i]);
	}
	cout << ret;

	return 0;
}