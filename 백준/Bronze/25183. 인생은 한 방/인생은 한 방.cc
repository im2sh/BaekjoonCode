#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s >> s; s += 'a';
	int prev = 'a', cnt = 0, mx = 0;
	for (auto l : s) {
		int cur = (int)l;
		if (cur == prev + 1 || cur == prev - 1) cnt++;
		else {
			mx = max(mx, cnt);
			cnt = 1;
		}
		prev = cur;
	}

	if (mx < 5) cout << "NO";
	else cout << "YES";
}