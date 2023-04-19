#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;
ll a, b, c;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Init() {
    cin >> a >> b >> c;
}

void solve() {
    cout << a + b + c << "\n";
}

int main(void) {
    fastIO();
    Init();
    solve();
    return 0;
}