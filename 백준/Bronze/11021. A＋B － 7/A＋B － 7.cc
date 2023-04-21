#include <iostream>


using namespace std;

int T;
int x, y;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    for (int i = 1; i <= T; i++) {
        cin >> x >> y;
        cout << "Case #" << i << ": " << x + y << "\n";

    }
}

void Init() {
    cin >> T;
}

int main(void) {
    fastIO();
    Init();
    solve();
    return 0;
}