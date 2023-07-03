#include <iostream>
using namespace std;
typedef long long ll;

ll N;
ll ans = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);
    
	cin >> N;
	for (ll i = 2; i <= N; i++) 
        ans *= i;

	cout << ans;
    return 0;
}