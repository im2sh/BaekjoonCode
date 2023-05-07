#include <iostream>

using namespace std;
int visited[28];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    for (int i = 0; i < 28; i++) {
        cin >> temp;
        visited[temp] = 1;
    }
}

void solve() {
    for (int i = 1; i <= 30; i++) {
        if (visited[i] == 0)
            cout << i << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}