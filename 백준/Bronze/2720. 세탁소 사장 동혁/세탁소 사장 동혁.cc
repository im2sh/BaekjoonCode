#include <iostream>

using namespace std;

int T,C;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Init(){
    cin >> T;
} 

void solve(){
    for (int i = 0; i < T; i++) {
		cin >> C;
		cout << C / 25<<" ";
		C = C % 25;
		cout << C / 10<<" ";
		C = C % 10;
		cout << C / 5 << " ";
		cout << C % 5 << "\n";
	}
}

int main() {
	FastIO();
    Init();
    solve();
	return 0;
}