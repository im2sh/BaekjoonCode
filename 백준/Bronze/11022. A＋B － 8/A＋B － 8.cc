#include <iostream>

int N;
using namespace std;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        cout << "Case #" << i + 1 << ": " << x << " + " << y << " = " << x + y << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}