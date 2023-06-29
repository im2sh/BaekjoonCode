#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);

	ll N; 
    cin >> N;
	cout << (N * (N - 1) * (N - 2)) / 6 << '\n' << 3;
    return 0;
}