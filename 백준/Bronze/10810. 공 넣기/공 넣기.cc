#include <iostream>

using namespace std;
int basket[100];

int N, M;
int i, j, k;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;

    for (int a = 1; a <= N; a++) {
        basket[a] = 0;
    }

    for (int a = 0; a < M; a++) {
        cin >> i >> j >> k;
        for (int b = i; b <= j; b++) {
            basket[b] = k;
        }
    }
}

void solve() {
    for (int a = 1; a <= N; a++) {
        cout << basket[a] << " ";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}